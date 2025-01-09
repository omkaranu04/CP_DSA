#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> g;
vector<ll> dist, parent;
void bfs()
{
    queue<ll> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        if (node == n)
        {
            vector<ll> path;
            while (node != -1)
            {
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            cout << path.size() << "\n";
            for (auto x : path)
                cout << x << " ";
            cout << "\n";
            return;
        }

        for (auto v : g[node])
        {
            if (dist[node] + 1 < dist[v])
            {
                dist[v] = dist[node] + 1;
                parent[v] = node;
                q.push(v);
            }
        }
    }
    cout << "IMPOSSIBLE\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    dist.resize(n + 1, 1e18);
    parent.resize(n + 1, -1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs();
    return 0;
}