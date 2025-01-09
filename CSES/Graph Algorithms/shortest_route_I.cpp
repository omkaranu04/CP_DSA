#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<pair<ll, ll>>> g;
vector<ll> visited, dist;
void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        ll node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = 1;
        for (auto v : g[node])
        {
            if (dist[node] + v.second < dist[v.first])
            {
                dist[v.first] = dist[node] + v.second;
                pq.push({dist[v.first], v.first});
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
    visited.resize(n + 1, 0);
    dist.resize(n + 1, 1e18);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    dijkstra(1);
    for (ll i = 1; i <= n; i++)
        cout << dist[i] << " ";
    return 0;
}