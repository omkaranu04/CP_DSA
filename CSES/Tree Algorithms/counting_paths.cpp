#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<vector<ll>> g, parent;
vector<ll> depth, ans;
void dfs(ll u, ll p, ll d)
{
    depth[u] = d;
    parent[u][0] = p;
    for (ll i = 1; i <= 20; i++)
    {
        if (parent[u][i - 1] != 0)
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for (ll v : g[u])
    {
        if (v != p)
            dfs(v, u, d + 1);
    }
}
ll lca(ll u, ll v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (ll i = 20; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1LL << i))
            u = parent[u][i];
    }
    if (u == v)
        return u;
    for (ll i = 20; i >= 0; i--)
    {
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
void dfs2(ll u, ll p)
{
    for (ll v : g[u])
    {
        if (v != p)
        {
            dfs2(v, u);
            ans[u] += ans[v];
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
    parent.resize(n + 1, vector<ll>(21, 0));
    depth.resize(n + 1, 0);
    ans.resize(n + 1, 0);

    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        ans[v]++;
        ans[u]++;
        ll w = lca(u, v);
        ans[w]--;
        if (parent[w][0] != 0)
            ans[parent[w][0]]--;
    }

    dfs2(1, 0);

    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}