// Edited Bellman Ford Algorithm
// Something different from the usual Bellman Ford Algorithm
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<pair<pair<ll, ll>, ll>> edges;
vector<vector<pair<ll, ll>>> g;
vector<ll> vis, par, dist;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    par.resize(n + 1, -1);
    dist.resize(n + 1, 1e18);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        edges.push_back(make_pair(make_pair(u, v), w));
    }
    ll start;
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        start = -1;
        for (auto e : edges)
        {
            ll u = e.first.first, v = e.first.second, w = e.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                start = v;
            }
        }
    }
    if (start == -1)
        cout << "NO\n";
    else
    {
        for (int i = 1; i <= n; i++)
            start = par[start];
        vector<ll> cycle;
        for (ll v = start;; v = par[v])
        {
            cycle.push_back(v);
            if (v == start && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for (auto x : cycle)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}