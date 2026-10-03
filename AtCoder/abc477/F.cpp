#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct SegTree
{
    ll n;
    vector<ll> st;
    SegTree(const ll &_n)
    {
        n = _n;
        st.resize(4 * n + 10, 0);
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
        update(1, 1, n, pos, val);
    }
    ll query(ll n, ll l, ll r, ll ql, ll qr)
    {
        if (r < ql || l > qr)
            return 0;
        if (ql <= l && r <= qr)
            return st[n];
        ll m = (l + r) / 2;
        ll lft = query(2 * n, l, m, ql, qr);
        ll rgt = query(2 * n + 1, m + 1, r, ql, qr);
        return lft + rgt;
    }
    ll query(ll l, ll r)
    {
        return query(1, 1, n, l, r);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, q;
    cin >> n >> m >> q;
    vector<ll> L(n + 1), R(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> L[i] >> R[i];

    vector<vector<ll>> stAt(m + 2), edAt(m + 2);
    for (ll i = 1; i <= n; i++)
    {
        stAt[L[i]].push_back(i);
        edAt[R[i] + 1].push_back(i);
    }
    vector<ll> A(q), B(q), ans(q, 0);
    vector<vector<pair<ll, ll>>> at(m + 1);
    for (ll i = 0; i < q; i++)
    {
        ll c, d;
        cin >> A[i] >> B[i] >> c >> d;
        at[d].push_back({i, 1});
        if (c - 1 >= 1)
            at[c - 1].push_back({i, -1});
    }
    SegTree cnt(n), sumL(n), full(n);
    for (ll x = 1; x <= m; x++)
    {
        for (ll i : edAt[x])
        {
            cnt.update(i, -1);
            sumL.update(i, -L[i]);
            full.update(i, R[i] - L[i] + 1);
        }
        for (ll i : stAt[x])
        {
            cnt.update(i, 1);
            sumL.update(i, L[i]);
        }
        for (auto [idx, sg] : at[x])
        {
            ll a = A[idx], b = B[idx];
            ans[idx] += (sg * (cnt.query(a, b) * (x + 1) - sumL.query(a, b) + full.query(a, b)));
        }
    }
    for (auto x : ans)
        cout << x << endl;
    return 0;
}