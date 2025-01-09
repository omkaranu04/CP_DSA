#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> dist;
int ans = 1e9;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int v : g[node])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[node] + 1;
                q.push(v);
            }
            else if (dist[node] <= dist[v])
            {
                ans = min(ans, dist[node] + dist[v] + 1);
                // cout << "ans : " << ans << endl;
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
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        dist.assign(n + 1, -1);
        bfs(i);
    }
    if (ans == 1e9)
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}