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
        a.resize(n);
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
        build(2 * n, l, m);
        build(2 * n + 1, m + 1, r);
        st[n] = min(st[2 * n], st[2 * n + 1]);
    }
    ll query(ll n, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return INF;
        if (ql <= l && qr >= r)
            return st[n];
        ll m = (l + r) / 2;
        return min(query(2 * n, l, m, ql, qr), query(2 * n + 1, m + 1, r, ql, qr));
    }
    ll Q(ll l, ll r)
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
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    SegTree seg(n, x);
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << seg.Q(--l, --r) << endl;
    }
    return 0;
}