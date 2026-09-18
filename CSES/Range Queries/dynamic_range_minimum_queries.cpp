#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll INF = 1e18;
struct SegTree
{
    ll n;
    vector<ll> a, st;
    SegTree(ll _n, const vector<ll> &_a)
    {
        n = _n;
        a = _a;
        st.resize(4 * n + 10);
        build(1, 0, n - 1);
    }
    void build(ll n, ll l, ll r)
    {
        if (l == r)
        {
            st[n] = a[l];
            return;
        }
        ll m = (l + r) / 2;
        build(n << 1, l, m);
        build((n << 1) + 1, m + 1, r);
        st[n] = min(st[n << 1], st[(n << 1) + 1]);
    }
    void update(ll n, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[n] = val;
            a[pos] = val;
            return;
        }

        ll m = (l + r) / 2;
        if (pos <= m)
            update(n << 1, l, m, pos, val);
        else
            update((n << 1 )+ 1, m + 1, r, pos, val);
        st[n] = min(st[n << 1], st[(n << 1) + 1]);
    }
    void update(ll pos, ll val)
    {
        update(1, 0, n - 1, pos, val);
    }
    ll query(ll n, ll l, ll r, ll ql, ll qr)
    {
        if (r < ql || l > qr)
            return INF;
        if (l >= ql && r <= qr)
            return st[n];
        ll m = (l + r) / 2;
        return min(query(n << 1, l, m, ql, qr), query((n << 1) + 1, m + 1, r, ql, qr));
    }
    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    SegTree seg(n, a);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll k, u;
            cin >> k >> u;
            k--;
            seg.update(k, u);
        }
        if (t == 2)
        {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << seg.query(a, b) << endl;
        }
    }
    return 0;
}