#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, q;
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
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    g.resize(n + 1);
    parent.resize(n + 1, vector<ll>(21, 0));
    depth.resize(n + 1, 0);

    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    dfs(1, 0, 0);

    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
    return 0;
}