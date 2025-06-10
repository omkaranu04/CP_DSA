#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<pair<ll, ll>> h;
vector<ll> p;
struct SegTree
{
    ll n;
    vector<ll> st;
    SegTree(ll _n) : n(_n), st(4 * _n + 4) {}
    void build(ll id, ll l, ll r)
    {
        if (l == r)
        {
            st[id] = 1;
            return;
        }
        ll mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        st[id] = st[2 * id] + st[2 * id + 1];
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
        st[id] = st[2 * id] + st[2 * id + 1];
    }
    ll query(ll id, ll l, ll r, ll x)
    {
        if (l == r)
            return l;
        ll mid = (l + r) / 2;
        if (st[2 * id] >= x)
            return query(2 * id, l, mid, x);
        else
            return query(2 * id + 1, mid + 1, r, x - st[2 * id]);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    h.resize(n);
    p.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i].first;
        h[i].second = i;
    }
    for (ll i = 0; i < n; i++)
        cin >> p[i];

    sort(h.begin(), h.end());

    SegTree st(n);
    st.build(1, 0, n - 1);

    vector<ll> ans(n);
    for (ll i = 0; i < n; i++)
    {
        ll taller = p[h[i].second];
        ll q = st.query(1, 0, n - 1, taller + 1);
        ans[q] = h[i].second;
        st.update(1, 0, n - 1, q, 0);
    }
    for (ll i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    return 0;
}