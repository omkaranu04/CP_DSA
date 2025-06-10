#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct SegTree
{
    ll n;
    vector<ll> a, st;
    SegTree(ll _n, vector<ll> &_a) : n(_n), a(_a), st(4 * _n + 4, 0) {}
    void build(ll idx, ll l, ll r)
    {
        if (l == r)
        {
            st[idx] = a[l];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        st[idx] = st[2 * idx] + st[2 * idx + 1];
    }
    void update(ll idx, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[idx] = val;
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * idx, l, mid, pos, val);
        else
            update(2 * idx + 1, mid + 1, r, pos, val);
        st[idx] = st[2 * idx] + st[2 * idx + 1];
    }
    ll query(ll idx, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return st[idx];
        ll mid = (l + r) / 2;
        return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
    }
};
ll n, q, timer;
vector<vector<ll>> g;
vector<ll> intime, outime, euler_tour, v;
void dfs(ll u, ll p)
{
    intime[u] = timer;
    timer++;

    for (ll v : g[u])
    {
        if (v != p)
            dfs(v, u);
    }

    outime[u] = timer;
    timer++;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    g.resize(n + 1);
    intime.resize(n + 1, 0);
    outime.resize(n + 1, 0);
    euler_tour.resize(2 * n, 0);
    v.resize(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    timer = 0;
    dfs(1, 0);

    for (ll i = 1; i <= n; i++)
    {
        euler_tour[intime[i]] = v[i];
        euler_tour[outime[i]] = -v[i];
    }

    ll m = euler_tour.size();
    SegTree segtree(m, euler_tour);
    segtree.build(1, 0, m);

    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll s, x;
            cin >> s >> x;
            segtree.update(1, 0, m, intime[s], x);
            segtree.update(1, 0, m, outime[s], -x);
        }
        else
        {
            ll s;
            cin >> s;
            cout << segtree.query(1, 0, m, 0, intime[s]) << endl;
        }
    }
    return 0;
}