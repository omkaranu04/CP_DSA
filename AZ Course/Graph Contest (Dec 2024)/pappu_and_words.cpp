#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<ll> a;
vector<string> words;
bool toposort(vector<set<ll>> &g, vector<ll> &indeg)
{
    queue<ll> q;
    ll cnt = 0;
    for (ll i = 0; i < 26; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        cnt++;
        for (auto v : g[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    return cnt == 26 || cnt == g.size();
}
bool isValid()
{
    vector<set<ll>> g(26);
    vector<ll> indeg(26, 0);
    for (ll i = 1; i < n; i++)
    {
        string &s1 = words[a[i - 1]];
        string &s2 = words[a[i]];

        ll len = min(s1.length(), s2.length());
        bool found = false;
        for (ll j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                ll u = s1[j] - 'a', v = s2[j] - 'a';
                if (g[u].find(v) == g[u].end())
                {
                    g[u].insert(v);
                    indeg[v]++;
                }
                found = true;
                break;
            }
        }

        if (found == false && s1.length() > s2.length())
            return false;
    }

    return toposort(g, indeg);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    words.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> words[i];
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    if (isValid())
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}