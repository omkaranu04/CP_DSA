#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> g;
// color method -> 1 - not yet, 2 - ongoing, 3 - done
// now the graph is directed
vector<int> color, parent;
bool exists;
void dfs(int node)
{
    if (exists)
        return;
    color[node] = 1;
    for (auto v : g[node])
    {
        if (color[v] == 1)
        {
            exists = true;
            return;
        }
        if (color[v] == 0)
            dfs(v);
    }
    color[node] = 2;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        g.clear();
        color.clear();
        parent.clear();
        exists = false;

        cin >> n >> m;
        g.resize(n + 1);
        color.resize(n + 1, 0);
        parent.resize(n + 1, -1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
                dfs(i);
        }
        if (exists)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}