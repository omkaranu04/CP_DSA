#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<pair<ll, ll>>> g;
vector<ll> vis, par;
void dfs(ll src)
{
    vis[src] = 1;
    for (auto x : g[src])
    {
        ll v = x.first, w = x.second;
        if (!vis[v])
        {
            par[v] = src;
            dfs(v);
        }
        else if (vis[v] == 1)
        {
            vector<ll> cycle;
            cycle.push_back(v);
            for (ll u = src; u != v; u = par[u])
                cycle.push_back(u);
            cycle.push_back(v);
            reverse(cycle.begin(), cycle.end());
            ll s = accumulate(cycle.begin(), cycle.end(), 0LL);
            if (s < 0)
            {
                cout << "YES\n";
                for (auto i : cycle)
                    cout << i << " ";
                cout << "\n";
                exit(0);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    par.resize(n + 1, -1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (ll i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    cout << "NO\n";
    return 0;
}