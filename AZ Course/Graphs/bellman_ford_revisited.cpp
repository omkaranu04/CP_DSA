#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<pair<ll, ll>>> g;
vector<pair<pair<ll, ll>, ll>> edges;
vector<ll> dist, visited;
bool negativeCycle()
{
    dist[1] = 0;
    // relax edges V - 1 number of times
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            ll u = e.first.first, v = e.first.second, w = e.second;
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    // now in Vth relaxation if edge weight changes it means we have a cycle
    for (auto e : edges)
    {
        ll u = e.first.first, v = e.first.second, w = e.second;
        if (dist[v] < dist[u] + w)
            return true;
    }
    return false;
}
ll maxWeightPath()
{
    if (negativeCycle())
        return -1;
    return dist[n];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    dist.resize(n + 1, -1e18);
    visited.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        edges.push_back({{u, v}, w});
    }
    cout << maxWeightPath() << "\n";
    return 0;
}