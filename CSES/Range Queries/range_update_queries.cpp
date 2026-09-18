#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct SegTree
{
    ll n;
    vector<ll> a, st;
    SegTree(const ll _n, const vector<ll> &_a)
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
            st[n] = 0;
            return;
        }
        ll m = (l + r) / 2;
        build(2 * n, l, m);
        build(2 * n + 1, m + 1, r);
        st[n] = st[2 * n] + st[2 * n + 1];
    }
    void update(ll n, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[n] += val;
            return;
        }
        ll m = (l + r) / 2;
        if (pos <= m)
            update(2 * n, l, m, pos, val);
        else
            update(2 * n + 1, m + 1, r, pos, val);
        st[n] = st[2 * n] + st[2 * n + 1];
    }
    void update(ll pos, ll val)
    {
        if (pos >= n)
            return;
        update(1, 0, n - 1, pos, val);
    }
    ll query(ll n, ll l, ll r, ll ql, ll qr)
    {
        if (r < ql || l > qr)
            return 0;
        if (ql <= l && qr >= r)
            return st[n];
        ll m = (l + r) / 2;
        return query(2 * n, l, m, ql, qr) + query(2 * n + 1, m + 1, r, ql, qr);
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
            ll a, b, u;
            cin >> a >> b >> u;
            a--;
            b--;
            seg.update(a, u);
            seg.update(b + 1, -u);
        }
        if (t == 2)
        {
            ll k;
            cin >> k;
            k--;
            cout << seg.query(0, k) + a[k] << endl;
        }
    }
    return 0;
}