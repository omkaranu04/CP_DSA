#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct SegTree
{
    ll n;
    vector<ll> st;
    SegTree(const ll _n)
    {
        n = _n;
        st.resize(4 * n + 10);
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
        update(1, 0, n - 1, pos, val);
    }
    ll query(ll n, ll l, ll r, ll ql, ll qr)
    {
        if (r < ql || l > qr)
            return 0;
        if (l >= ql && r <= qr)
            return st[n];
        ll m = (l + r) / 2;
        return query(2 * n, l, m, ql, qr) + query(2 * n + 1, m + 1, r, ql, qr);
    }
    ll query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
struct Query
{
    char type;
    ll a, b;
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> p(n);
    for (auto &x : p)
        cin >> x;
    vector<Query> queries;
    vector<ll> coords;
    for (auto x : p)
        coords.push_back(x);
    for (ll i = 0; i < q; i++)
    {
        char t;
        ll a, b;
        cin >> t >> a >> b;
        queries.push_back({t, a, b});
        if (t == '!')
            coords.push_back(b);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    SegTree seg(coords.size());
    auto getIndex = [&](ll x)
    {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    };

    // initial salaries
    for (auto x : p)
        seg.update(getIndex(x), 1);

    for (auto [t, a, b] : queries)
    {
        if (t == '!')
        {
            seg.update(getIndex(p[a - 1]), -1);
            seg.update(getIndex(b), 1);
            p[a - 1] = b;
        }
        else
        {
            ll l = lower_bound(coords.begin(), coords.end(), a) - coords.begin();
            ll r = upper_bound(coords.begin(), coords.end(), b) - coords.begin() - 1;
            cout << seg.query(l, r) << endl;
        }
    }
    return 0;
}