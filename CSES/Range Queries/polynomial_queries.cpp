#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
typedef struct Node
{
    ll sum;
    ll a, d;
    Node() : sum(0), a(0), d(0) {}
} node;
struct SegTree
{
    ll n;
    vector<ll> a;
    vector<node> st;

    SegTree(ll _n, vector<ll> &_a) : n(_n), a(_a), st(4 * _n + 4) {}
    void build(ll id, ll l, ll r)
    {
        if (l == r)
        {
            st[id].sum = a[l];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        st[id].sum = st[2 * id].sum + st[2 * id + 1].sum;
    }
    // helper functions for AP functionality
    ll ap_sum(ll a, ll d, ll n)
    {
        return (2 * a + (n - 1) * d) * n / 2;
    }
    void apply(ll id, ll l, ll r, ll a, ll d)
    {
        ll len = r - l + 1;
        st[id].sum += ap_sum(a, d, len);
        st[id].a += a;
        st[id].d += d;
    }
    void pushdown(ll id, ll l, ll r)
    {
        ll a = st[id].a, d = st[id].d;
        if (a == 0 && d == 0)
            return;
        ll mid = (l + r) / 2;
        apply(2 * id, l, mid, a, d);
        apply(2 * id + 1, mid + 1, r, a + (mid - l + 1) * d, d);
        st[id].a = st[id].d = 0;
    }

    void update(ll id, ll l, ll r, ll ql, ll qr, ll global_L)
    {
        if (r < ql || qr < l)
            return;
        if (l >= ql && r <= qr)
        {
            ll ff = l - global_L + 1;
            apply(id, l, r, ff, 1);
            return;
        }
        pushdown(id, l, r);
        ll mid = (l + r) / 2;
        update(2 * id, l, mid, ql, qr, global_L);
        update(2 * id + 1, mid + 1, r, ql, qr, global_L);
        st[id].sum = st[2 * id].sum + st[2 * id + 1].sum;
    }

    ll query(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (r < ql || qr < l)
            return 0;
        if (l >= ql && r <= qr)
            return st[id].sum;
        pushdown(id, l, r);
        ll mid = (l + r) / 2;
        return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> t(n);
    for (ll i = 0; i < n; i++)
        cin >> t[i];

    SegTree segtree(n, t);
    segtree.build(1, 0, n - 1);
    while (q--)
    {
        ll t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        if (t == 1)
        {
            segtree.update(1, 0, n - 1, a, b, a);
        }
        else
        {
            cout << segtree.query(1, 0, n - 1, a, b) << endl;
        }
    }
    return 0;
}