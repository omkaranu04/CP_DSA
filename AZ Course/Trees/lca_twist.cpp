#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> g, par; // par is for binary lifting
vector<ll> dep;
void dfs(ll node, ll parent, ll depth)
{
    dep[node] = depth;
    par[node][0] = parent;

    for (int i = 1; i <= 20; i++)
    {
        if (par[node][i - 1] != 0)
            par[node][i] = par[par[node][i - 1]][i - 1];
    }
    for (auto v : g[node])
    {
        if (v != parent)
            dfs(v, node, depth + 1);
    }
}
ll lca(ll u, ll v)
{
    // u will be higher depth always ensure
    if (dep[u] < dep[v])
        swap(u, v);

    for (int i = 20; i >= 0; i--)
    {
        if ((dep[u] - dep[v]) & (1 << i)) // how much we have to lift u will depend on the set bits of the length to be lifted
            u = par[u][i];
    }

    // v is the ancestor of u
    if (u == v)
        return u;

    for (int i = 20; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}
void solve()
{
    g.clear();
    par.clear();
    dep.clear();

    ll n, q;
    cin >> n;
    g.assign(n + 1, vector<ll>());
    dep.assign(n + 1, 0);
    par.assign(n + 1, vector<ll>(21, 0)); // upto max 2^20, usually suffice for all purposes
    for (ll i = 1; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0, 0); // 1 as the OG root of the tree

    // queries
    cin >> q;
    while (q--)
    {
        ll u, v, z;
        cin >> u >> v >> z;
        ll l = lca(u, v), a = lca(u, z), b = lca(v, z);

        if (a == l)
            cout << b << "\n";
        else if (b == l)
            cout << a << "\n";
        else
            cout << l << "\n";
    }
    return;
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