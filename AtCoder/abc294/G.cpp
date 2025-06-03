#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
// w/o loss of generality assume 1 as root of tree
ll n, q, timer;
vector<vector<ll>> g, parent;
vector<ll> val, depth, intime, outtime;
vector<pair<pair<ll, ll>, ll>> edges;
vector<ll> euler_tour;

void dfs(ll u, ll par, ll dep)
{
    intime[u] = timer;
    timer++;
    depth[u] = dep;
    parent[u][0] = par;

    for (ll i = 1; i <= 20; i++)
    {
        if (parent[u][i - 1] != 0)
            parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }

    for (auto v : g[u])
    {
        if (v != par)
        {
            dfs(v, u, dep + 1);
        }
    }

    outtime[u] = timer;
    timer++;
}
ll lca(ll u, ll v)
{
    if (depth[u] < depth[v])
        swap(u, v); // keep u at a greater depth always

    for (ll i = 20; i >= 0; i--)
    {
        ll diff = depth[u] - depth[v];
        if (diff & (1LL << i))
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

struct SegTree
{
    ll n;
    vector<ll> tree, a; // a is the array on which we are building the segtree

    SegTree(ll _n, vector<ll> &x)
    {
        n = _n;
        tree.resize(4 * _n + 4, 0);
        a.resize(_n + 1);
        for (ll i = 0; i < x.size(); i++)
            a[i] = x[i];
    }

    void build(ll idx, ll l, ll r)
    {
        if (l == r)
        {
            tree[idx] = a[l];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    void update(ll idx, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            tree[idx] = val;
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    ll query(ll idx, ll l, ll r, ll ql, ll qr)
    {
        if (l > qr || r < ql)
            return 0LL;
        if (l >= ql && r <= qr)
            return tree[idx];
        ll mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    g.resize(n + 1);
    parent.resize(n + 1, vector<ll>(21, 0));
    val.resize(n + 1);
    depth.resize(n + 1, 0);
    edges.resize(n + 1);
    intime.resize(n + 1);
    outtime.resize(n + 1);

    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = make_pair(make_pair(u, v), w);
    }

    timer = 0;
    dfs(1, 0, 0);

    for (auto &x : edges)
    {
        ll u = x.first.first, v = x.first.second;
        ll w = x.second;

        if (depth[u] < depth[v])
            val[v] = w; // v is deeper so it gets the value
        else
            val[u] = w;
    }

    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << intime[i] << " " << outtime[i] << endl;
    // }

    euler_tour.resize(2 * n, 0);
    for (ll i = 1; i <= n; i++)
    {
        euler_tour[intime[i]] += val[i];
        euler_tour[outtime[i]] -= val[i];
    }

    // for (ll i = 0; i < 2 * n; i++)
    //     cout << euler_tour[i] << " ";
    // cout << endl;

    // Build Segment Tree on euler_tour
    SegTree segtree(euler_tour.size(), euler_tour);
    segtree.build(1, 0, euler_tour.size() - 1);

    ll Q;
    cin >> Q;
    while (Q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll i, w;
            cin >> i >> w;
            // change the weight of edge i to w
            pair<pair<ll, ll>, ll> &tmp = edges[i]; // u, v, w;
            if (depth[tmp.first.first] > depth[tmp.first.second])
            {
                tmp.second = w; // update the weight in edges vector
                // u is at a greater depth
                segtree.update(1, 0, euler_tour.size() - 1, intime[tmp.first.first], w);
                segtree.update(1, 0, euler_tour.size() - 1, outtime[tmp.first.first], -w);
            }
            else
            {
                tmp.second = w;
                // v is at a greater depth
                segtree.update(1, 0, euler_tour.size() - 1, intime[tmp.first.second], w);
                segtree.update(1, 0, euler_tour.size() - 1, outtime[tmp.first.second], -w);
            }
        }
        else
        {
            ll u, v;
            cin >> u >> v;
            ll lcauv = lca(u, v);

            ll dist_u = segtree.query(1, 0, euler_tour.size() - 1, 0, intime[u]);
            ll dist_v = segtree.query(1, 0, euler_tour.size() - 1, 0, intime[v]);
            ll dist_lca = segtree.query(1, 0, euler_tour.size() - 1, 0, intime[lcauv]);

            ll ans = dist_u + dist_v - 2 * dist_lca;
            cout << ans << endl;
        }
    }
    return 0;
}