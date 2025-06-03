#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, d, r;
vector<ll> h, dp;
vector<pair<ll, ll>> a;
struct SegTree
{
    ll n;
    vector<ll> st;
    SegTree(ll _n) : n(_n)
    {
        st.resize(4 * n + 4, -1e18);
    }

    void update(ll node, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[node] = val;
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * node, l, mid, pos, val);
        else
            update(2 * node + 1, mid + 1, r, pos, val);

        st[node] = max(st[2 * node], st[2 * node + 1]);
    }

    ll query(ll node, ll l, ll r, ll L, ll R)
    {
        if (r < L || R < l)
            return -1e18;
        if (L <= l && r <= R)
            return st[node];
        ll mid = (l + r) / 2;
        return max(query(2 * node, l, mid, L, R), query(2 * node + 1, mid + 1, r, L, R));
    }
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d >> r;
    h.resize(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> h[i];
        a.push_back({h[i], i});
    }
    sort(a.begin(), a.end());

    dp.resize(n + 1, 0);
    SegTree st(n);
    ll ans = 0, p = 0;
    for (auto &[h, idx] : a)
    {
        while (p < n && a[p].first <= h - d)
        {
            ll j = a[p].second;
            st.update(1, 1, n, j, dp[j]);
            p++;
        }

        ll l = max(1LL, idx - r);
        ll rr = min(n, idx + r);
        ll tmp = st.query(1, 1, n, l, rr);

        dp[idx] = (tmp < 0 ? 0 : tmp + 1);
        ans = max(ans, dp[idx]);
    }
    cout << ans << endl;
    return 0;
}