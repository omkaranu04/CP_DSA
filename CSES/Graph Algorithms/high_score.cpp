// mostly its bellman ford algorithm
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<pair<pair<ll, ll>, ll>> edges;
vector<ll> dist, marked, visited;
bool bellman_ford()
{
    dist[1] = 0;
    marked[n] = 1;
    // to find the max score
    for (ll i = 1; i <= n - 1; i++)
    {
        for (auto e : edges)
        {
            ll u = e.first.first, v = e.first.second, w = e.second;
            if (dist[u] != 1e18)
            {
                dist[v] = min(dist[v], dist[u] + w);
            }

            if (marked[v])
                marked[u] = 1;
        }
    }

    for (auto e : edges)
    {
        ll u = e.first.first, v = e.first.second, w = e.second;
        if (dist[u] != 1e18 && dist[v] > dist[u] + w && marked[v])
        {
            return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    dist.resize(n + 1, 1e18);
    marked.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({{u, v}, -w});
    }
    if (bellman_ford())
    {
        cout << -dist[n] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}