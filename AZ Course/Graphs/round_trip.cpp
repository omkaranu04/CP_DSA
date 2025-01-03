#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
// color method -> 1 - not yet, 2 - ongoing, 3 - done
vector<int> color, parent;
int start = -1, endx;
bool dfs(int node, int par)
{
    color[node] = 2;
    for (int v : g[node])
    {
        if (v == par)
            continue;
        if (color[v] == 1)
        {
            parent[v] = node;
            if (dfs(v, node))
                return true;
        }
        else if (color[v] == 2)
        {
            start = v;
            endx = node;
            return true;
        }
    }
    color[node] = 3;
    return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1, 1);
    parent.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1 && dfs(i, parent[i]))
            break;
    }
    if (start == -1)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}