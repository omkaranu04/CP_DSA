#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, q;
vector<vector<ll>> g, parent, dp;
vector<array<ll, 3>> edges;
vector<ll> wts, depth;
// DFS for LCA purposes
void dfs(ll node, ll p, ll d)
{
    parent[node][0] = p;
    depth[node] = d;

    for (ll i = 1; i <= 20; i++)
    {
        if (parent[node][i - 1] != 0)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }

    for (auto v : g[node])
    {
        if (v != p)
        {
            dfs(v, node, d + 1);
        }
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
// DFS to fill the dp array
void dfs2(ll node, ll p)
{
    if (p != 0)
    {
        for (ll i = 0; i <= 20; i++)
            dp[node][i] = dp[p][i];
    }
    for (ll i = 0; i <= 20; i++)
    {
        if ((wts[node] & (1LL << i)))
            dp[node][i]++;
    }
    for (auto v : g[node])
    {
        if (v != p)
            dfs2(v, node);
    }
}
void solve()
{
    g.clear();
    parent.clear();
    dp.clear();
    edges.clear();
    wts.clear();

    cin >> n >> q;
    g.resize(n + 1);
    depth.resize(n + 1, 0);
    parent.resize(n + 1, vector<ll>(21, 0));
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u, v, w});
    }

    dfs(1, 0, 0);
    wts.resize(n + 1, 0);
    for (auto x : edges)
    {
        ll u = x[0], v = x[1], w = x[2];
        if (depth[u] > depth[v])
            wts[u] = w;
        else
            wts[v] = w;
    }

    // fills in the bit data
    dp.resize(n + 1, vector<ll>(21, 0));
    dfs2(1, 0);

    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        ll lcauv = lca(u, v);
        ll len = depth[u] + depth[v] - 2 * depth[lcauv];
        ll o = 0, a = 0, x = 0;
        for (ll i = 0; i <= 20; i++)
        {
            ll no1s = dp[u][i] + dp[v][i] - 2 * dp[lcauv][i];
            if (no1s > 0)
                o |= (1LL << i);
            if (no1s == len)
                a |= (1LL << i);
            if (no1s & 1)
                x |= (1LL << i);
        }
        cout << o + a + x << endl;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}