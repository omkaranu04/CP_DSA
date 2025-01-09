#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> g, bin_lift;
vector<ll> dep, par, values;
void dfs(ll node, ll parent, ll depth)
{
    par[node] = parent;
    dep[node] = depth;
    bin_lift[node][0] = parent;

    for (int i = 1; i <= 20; i++)
    {
        if (bin_lift[node][i - 1] != 0)
            bin_lift[node][i] = bin_lift[bin_lift[node][i - 1]][i - 1];
    }

    for (auto v : g[node])
    {
        if (v != parent)
            dfs(v, node, depth + 1);
    }
}
ll lca(ll u, ll v)
{
    if (dep[u] < dep[v])
        swap(u, v);

    for (int i = 20; i >= 0; i--)
    {
        if ((dep[u] - dep[v]) & (1 << i))
            u = bin_lift[u][i];
    }

    if (u == v)
        return u;

    for (int i = 20; i >= 0; i--)
    {
        if (bin_lift[u][i] != bin_lift[v][i])
        {
            u = bin_lift[u][i];
            v = bin_lift[v][i];
        }
    }
    return bin_lift[u][0];
}
void push_all(ll node, ll parent)
{
    for (auto v : g[node])
    {
        if (v != parent)
        {
            push_all(v, node);
            values[node] += values[v];
        }
    }
}
void solve()
{
    g.clear();
    bin_lift.clear();
    dep.clear();
    par.clear();
    values.clear();

    ll n;
    cin >> n;
    g.assign(n + 1, vector<ll>());
    bin_lift.assign(n + 1, vector<ll>(21, 0));
    dep.assign(n + 1, 0);
    par.assign(n + 1, 0);
    values.assign(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0, 0);

    ll q;
    cin >> q;

    while (q--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        values[x] += z;
        values[y] += z;
        ll lca_xy = lca(x, y);
        if (lca_xy != 0)
            values[lca_xy] -= z;
        if (par[lca_xy] != 0)
            values[par[lca_xy]] -= z;
    }
    push_all(1, 0);
    // cout << "ANS : ";
    for (int i = 1; i <= n; i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
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