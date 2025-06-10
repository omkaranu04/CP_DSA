#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

typedef struct node
{
    ll sum, lazy_set, lazy_add;
    ll l, r;
    node(ll _l = 0, ll _r = 0, ll _sum = 0, ll _lazy_add = 0, ll _lazy_set = 0) : sum(_sum), lazy_set(_lazy_set), lazy_add(_lazy_add), l(_l), r(_r) {}
} Node;
struct SegTree
{
    ll n;
    vector<ll> a;
    vector<Node> segtree;
    SegTree(ll _n, vector<ll> &_a) : n(_n), a(_a), segtree(4 * _n + 4) {}

    void build(ll id, ll l, ll r)
    {
        segtree[id].l = l;
        segtree[id].r = r;
        if (l == r)
        {
            segtree[id].sum = a[l];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        segtree[id].sum = segtree[2 * id].sum + segtree[2 * id + 1].sum;
    }

    void pushdown(ll id)
    {
        ll l = segtree[id].l, r = segtree[id].r;
        if (segtree[id].lazy_set)
        {
            segtree[id].sum = (r - l + 1) * 1LL * segtree[id].lazy_set;
            if (l < r) // non leaf node only
            {
                segtree[2 * id].lazy_set = segtree[id].lazy_set;
                segtree[2 * id].lazy_add = 0;
                segtree[2 * id + 1].lazy_set = segtree[id].lazy_set;
                segtree[2 * id + 1].lazy_add = 0;
            }
            segtree[id].lazy_set = 0;
        }
        if (segtree[id].lazy_add)
        {
            segtree[id].sum += (r - l + 1) * 1LL * segtree[id].lazy_add;
            if (l < r) // non leaf node only
            {
                segtree[2 * id].lazy_add += segtree[id].lazy_add;
                // segtree[2 * id].lazy_set = 0;
                segtree[2 * id + 1].lazy_add += segtree[id].lazy_add;
                // segtree[2 * id + 1].lazy_set = 0;
            }
            segtree[id].lazy_add = 0;
        }
    }

    void update(ll id, ll l, ll r, ll ql, ll qr, ll val, bool to_set)
    {
        pushdown(id);
        if (l > qr || r < ql)
            return;
        if (l >= ql && r <= qr)
        {
            if (!to_set)
            {
                segtree[id].lazy_add += val;
                // segtree[id].lazy_set = 0;
            }
            else
            {
                segtree[id].lazy_set = val;
                segtree[id].lazy_add = 0;
            }
            pushdown(id);
            return;
        }
        ll mid = (l + r) / 2;
        update(2 * id, l, mid, ql, qr, val, to_set);
        update(2 * id + 1, mid + 1, r, ql, qr, val, to_set);
        segtree[id].sum = segtree[2 * id].sum + segtree[2 * id + 1].sum;
    }

    ll query(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return 0;
        pushdown(id);
        if (l >= ql && r <= qr)
            return segtree[id].sum;
        ll mid = (l + r) / 2;
        return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    vector<ll> t(n);
    for (ll i = 0; i < n; i++)
        cin >> t[i];
    SegTree st(n, t);
    st.build(1, 0, n - 1);

    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            a--, b--;
            st.update(1, 0, n - 1, a, b, x, false);
        }
        else if (t == 2)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            a--, b--;
            st.update(1, 0, n - 1, a, b, x, true);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            cout << st.query(1, 0, n - 1, a, b) << endl;
        }
    }
    return 0;
}