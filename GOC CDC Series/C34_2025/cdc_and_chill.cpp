#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, m;
vector<ll> enjoy;
vector<vector<pair<ll, ll>>> g;
vector<array<ll, 3>> edges;
void solve()
{
    g.clear();
    enjoy.clear();
    edges.clear();
    
    cin >> n >> m;
    g.resize(n + 1);
    enjoy.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> enjoy[i];
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edges.push_back({u, v, w});
    }
    ll ans = INT_MIN;
    for (auto &x : edges)
    {
        ll u = x[0], v = x[1], w = x[2];
        vector<pair<ll, ll>> neighu, neighv;
        for (auto y : g[u])
            if (y.first != v)
                neighu.push_back(y);
        for (auto y : g[v])
            if (y.first != u)
                neighv.push_back(y);

        for (auto &[nu, nuw] : neighu)
        {
            for (auto &[nv, nvw] : neighv)
            {
                if (nu != nv && nu != u && nu != v && nv != v && nv != u)
                {
                    ll e = enjoy[u] + enjoy[v] + enjoy[nu] + enjoy[nv];
                    ll b = w + nuw + nvw;
                    ans = max(ans, e - b);
                }
            }
        }
    }
    if (ans == INT_MIN)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}