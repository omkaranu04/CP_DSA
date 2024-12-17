#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, int depth, vector<int> &dep, vector<int> &par, vector<int> g[])
{
    dep[node] = depth;
    par[node] = parent;

    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1, dep, par, g);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> g[n + 1], dep(n + 1), par(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // for tree diameter
    int maxcn = 1;
    dfs(1, 0, 0, dep, par, g);
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] > dep[maxcn])
        {
            maxcn = i;
        }
    }
    dfs(maxcn, 0, 0, dep, par, g);
    int maxd = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dep[i] > dep[maxd])
        {
            maxd = i;
        }
    }
    int diameter = dep[maxd];
    if (diameter % 2)
    {
        cout << -1 << endl;
    }
    else
    {
        int centre = maxd;
        for (int i = 0; i < diameter / 2; i++)
        {
            centre = par[centre];
        }
        cout << centre << endl;
    }
    return 0;
}