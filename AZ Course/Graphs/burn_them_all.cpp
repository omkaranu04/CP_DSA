#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ii pair<int, int>
int n, m;
vector<vector<ii>> g;
vector<pair<pair<int, int>, int>> edges;
vector<int> dist, visited;
void dijkstra(int src)
{
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        if (visited[node])
            continue;

        visited[node] = 1;
        for (auto v : g[node])
        {
            int neigh = v.first, w = v.second;
            if (dist[node] + w < dist[neigh])
            {
                dist[neigh] = dist[node] + w;
                pq.push({dist[neigh], neigh});
            }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    dist.resize(n + 1, 1e18);
    visited.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edges.push_back({{u, v}, w});
    }
    int src;
    cin >> src;
    dijkstra(src);
    // for (int i = 1; i <= n; i++)
    //     cout << dist[i] << " ";
    int ans = -1e18;
    for (auto e : edges)
    {
        int temp;
        int u = e.first.first, v = e.first.second, w = e.second;
        if (abs(dist[u] - dist[v]) >= w)
            temp = (min(dist[u], dist[v]) + w) * 10;
        else
            temp = (dist[u] + dist[v] + w) * 5;
        ans = max(ans, temp);
    }
    cout << ans << "\n";
    return 0;
}