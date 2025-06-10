#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, m;
struct SegTree
{
    ll n;
    vector<ll> a, st;
    SegTree(ll _n, const vector<ll> &_a) : n(_n), a(_a), st(4 * _n + 4) {}
    void build(ll id, ll l, ll r)
    {
        if (l == r)
        {
            st[id] = a[l];
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        st[id] = st[2 * id] + st[2 * id + 1];
    }
    ll query(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return st[id];
        ll mid = (l + r) / 2;
        return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
    }
    void update(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return;
        if (st[id] == (ll)(r - l + 1))
            return;
        if (l == r)
        {
            st[id] = (ll)sqrt(st[id]);
            return;
        }
        ll mid = (l + r) / 2;
        update(2 * id, l, mid, ql, qr);
        update(2 * id + 1, mid + 1, r, ql, qr);
        st[id] = st[2 * id] + st[2 * id + 1];
    }
};
void solve(ll testcase)
{
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    SegTree st(n, a);
    st.build(1, 0, n - 1);

    cout << "Case #" << testcase << ":\n";
    cin >> m;
    while (m--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        if (x > y)
            swap(x, y);
        x--, y--;
        if (t == 0) // modify
        {
            st.update(1, 0, n - 1, x, y);
        }
        else // sum query
        {
            cout << st.query(1, 0, n - 1, x, y) << endl;
        }
    }

    cout << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    while ((cin >> n))
    {
        solve(t);
        t++;
    }
    return 0;
}