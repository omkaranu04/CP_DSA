#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, q;
vector<ll> p;
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
        st[id] = min(st[2 * id], st[2 * id + 1]);
    }
    void update(ll id, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[id] = val;
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * id, l, mid, pos, val);
        else
            update(2 * id + 1, mid + 1, r, pos, val);
        st[id] = min(st[2 * id], st[2 * id + 1]);
    }
    ll query(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return 1e18;
        if (l >= ql && r <= qr)
            return st[id];
        ll mid = (l + r) / 2;
        return min(query(2 * id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    p.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    vector<ll> up(n), down(n);
    for (ll i = 0; i < n; i++)
    {
        up[i] = p[i] + i;
        down[i] = p[i] - i;
    }
    SegTree stup(n, up), stdown(n, down);
    stup.build(1, 0, n - 1);
    stdown.build(1, 0, n - 1);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll k, x;
            cin >> k >> x;
            k--;
            stup.update(1, 0, n - 1, k, x + k);
            stdown.update(1, 0, n - 1, k, x - k);
        }
        else
        {
            ll k;
            cin >> k;
            k--;
            ll ans = min(stup.query(1, 0, n - 1, k, n - 1) - k, stdown.query(1, 0, n - 1, 0, k) + k);
            cout << ans << endl;
        }
    }
    return 0;
}