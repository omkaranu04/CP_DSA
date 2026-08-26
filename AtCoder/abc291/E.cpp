#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<vector<ll>> g;
vector<ll> indeg, ans;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    indeg.resize(n + 1, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        indeg[y]++;
    }
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 1; i <= n; i++)
        if (indeg[i] == 0)
            pq.push(i);
    bool unique = true;
    while (!pq.empty())
    {
        if (pq.size() > 1)
            unique = false;
        ll u = pq.top();
        pq.pop();
        ans.push_back(u);
        for (auto v : g[u])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                pq.push(v);
        }
    }
    if (1LL * ans.size() != n || !unique)
        cout << "No\n";
    else
    {
        cout << "Yes\n";
        vector<ll> ans2(n + 1);
        for (ll i = 1; i <= n; i++)
            ans2[ans[i - 1]] = i;
        for (ll i = 1; i <= n; i++)
            cout << ans2[i] << " ";
    }
    return 0;
}