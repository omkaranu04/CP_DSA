#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> a;
vector<vector<int>> adj;
vector<ll> mx, mn;

void dfs(int u, int p)
{
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        mx[v] = max(a[v], a[v] - mn[u]);
        mn[v] = min(a[v], a[v] - mx[u]);
        dfs(v, u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        a.assign(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        adj.assign(n + 1, {});
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        mx.assign(n + 1, 0);
        mn.assign(n + 1, 0);

        mx[1] = mn[1] = a[1];
        dfs(1, 0);

        for (int i = 1; i <= n; i++)
        {
            cout << mx[i] << (i < n ? ' ' : '\n');
        }
    }
    return 0;
}
