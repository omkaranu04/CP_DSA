#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n;
vector<vector<ll>> g, parent;
vector<ll> depth;
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
ll modpow(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = modpow(a, b / 2, mod);
    res = (res * 1LL * res) % mod;
    if (b % 2)
        return (res * 1LL * a) % mod;
    else
        return res;
}
void solve()
{
    g.clear();
    parent.clear();
    depth.clear();

    cin >> n;
    g.resize(n + 1);
    parent.resize(n + 1, vector<ll>(21, 0));
    depth.resize(n + 1);

    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);

    vector<ll> leaves;
    for (ll i = 2; i <= n; i++)
    {
        if (g[i].size() == 1)
            leaves.push_back(i);
    }

    if (leaves.size() > 2)
    {
        cout << 0 << endl;
        return;
    }
    if (leaves.size() == 1)
    {
        cout << modpow(2, n, mod) << endl;
        return;
    }

    ll lcal = lca(leaves[0], leaves[1]);
    ll z = depth[lcal];
    ll x = depth[leaves[0]] - z;
    ll y = depth[leaves[1]] - z;

    if (x == y)
    {
        cout << modpow(2, z + 2, mod) << endl;
    }
    else
    {
        ll t1 = modpow(2, z + 1 + abs(x - y), mod);
        ll t2 = modpow(2, z + abs(x - y), mod);
        t1 = (t1 + t2) % mod;
        cout << t1 << endl;
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