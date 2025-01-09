#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, int depth, vector<int> &dep, vector<int> &par, vector<int> &sz, vector<int> g[])
{
    par[node] = parent;
    dep[node] = depth;
    sz[node] = 1;

    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1, dep, par, sz, g);
            sz[node] += sz[v];
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
    vector<int> g[n + 1], par(n + 1), dep(n + 1), sz(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v});
    }
    dfs(1, 0, 0, dep, par, sz, g);
    long long int ans = 0;
    for (auto x : edges)
    {
        int u = x.first;
        int v = x.second;
        if (par[u] == v) // v is the parent of u
        {
            ans += (sz[u] * 1LL * (n - sz[u]));
        }
        else
        {
            ans += (sz[v] * 1LL * (n - sz[v]));
        }
    }
    cout << ans << endl;
    return 0;
}