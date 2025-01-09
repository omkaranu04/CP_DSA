#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, int depth, vector<int> &par, vector<int> &sub, vector<int> &dep, vector<int> g[])
{
    par[node] = parent;
    dep[node] = depth;
    sub[node] = 1;
    for (auto i : g[node])
    {
        if (i != parent)
        {
            dfs(i, node, depth + 1, par, sub, dep, g);
            sub[node] += sub[i];
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
    vector<int> g[n + 1], par(n + 1), sub(n + 1), dep(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1, 0, 0, par, sub, dep, g);
    for (int i = 1; i <= n; i++)
    {
        cout << sub[i] - 1 << " ";
    }
    return 0;
}