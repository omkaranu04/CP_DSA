#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> color;
// to check if the graph is bipartite or not
bool dfs(int node, int col)
{
    color[node] = col;
    for (int v : g[node])
    {
        if (color[v] == -1)
        {
            if (dfs(v, 1 - col) == false)
                return false;
        }
        else if (color[v] == color[node])
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (dfs(i, 0) == false)
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}