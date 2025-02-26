#include <bits/stdc++.h>
using namespace std;
#define int long long int

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

int dfs2(int node, int parent, int depth, vector<int> g[], int req_depth)
{
    int cnt = 0;
    if (depth == req_depth)
    {
        cnt = 1;
    }

    for (auto v : g[node])
    {
        if (v != parent)
        {
            cnt += dfs2(v, node, depth + 1, g, req_depth);
        }
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    vector<int> g[n + 1], dep(n + 1), par(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Find the diameter of the tree
    dfs(1, 0, 0, dep, par, g);
    int farthest = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[farthest])
        {
            farthest = i;
        }
    }

    dfs(farthest, 0, 0, dep, par, g);
    farthest = 1;
    for (int i = 2; i <= n; i++)
    {
        if (dep[i] > dep[farthest])
        {
            farthest = i;
        }
    }

    int diameter = dep[farthest];

    if (diameter % 2 == 0)
    {
        // Even diameter case
        int center = farthest;
        for (int i = 0; i < diameter / 2; i++)
        {
            center = par[center];
        }

        int sum1 = 0, sum2 = 0;
        for (auto neighbor : g[center])
        {
            int count = dfs2(neighbor, center, 1, g, diameter / 2);
            sum1 += count;
            sum2 += count * count;
        }

        cout << ((sum1 * sum1) - sum2) / 2 << endl;
    }
    else
    {
        // Odd diameter case
        int center = farthest;
        for (int i = 0; i < diameter / 2; i++)
        {
            center = par[center];
        }

        int center1 = center;
        int center2 = par[center];

        int count1 = dfs2(center1, center2, 0, g, diameter / 2);
        int count2 = dfs2(center2, center1, 0, g, diameter / 2);

        cout << count1 * count2 << endl;
    }

    return 0;
}
