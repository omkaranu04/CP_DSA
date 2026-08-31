#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> g(26);
    vector<ll> indeg(26, 0);
    vector<string> names(n);
    for (auto &s : names)
        cin >> s;
    for (ll i = 0; i < n - 1; i++)
    {
        string s = names[i], t = names[i + 1];
        ll len = min(s.length(), t.length()), j = 0;
        while (j < len && s[j] == t[j])
            j++;
        if (j == len)
        {
            // prefix case
            if (s.length() > t.length())
            {
                cout << "Impossible\n";
                return 0;
            }
        }
        else
        {
            ll u = s[j] - 'a', v = t[j] - 'a';
            g[u].push_back(v);
            indeg[v]++;
        }
    }

    // Topological Sorting
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<ll> topo;
    for (ll i = 0; i < 26; i++)
        if (indeg[i] == 0)
            pq.push(i);
    while (!pq.empty())
    {
        ll u = pq.top();
        pq.pop();
        topo.push_back(u);
        for (auto v : g[u])
        {
            indeg[v]--;
            if (!indeg[v])
                pq.push(v);
        }
    }
    if (topo.size() != 26)
    {
        cout << "Impossible";
        return 0;
    }
    for (ll i = 0; i < 26; i++)
        cout << char(topo[i] + 'a');
    return 0;
}