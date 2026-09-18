#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct SegTree
{
    ll n;
    vector<ll> h;
    vector<pair<ll, ll>> st; // (max, idx)
    SegTree(const ll _n, const vector<ll> &_h)
    {
        n = _n;
        h = _h;
        st.resize(4 * n + 10);
        build(1, 0, n - 1);
    }
    pair<ll, ll> merge(ll i, ll j)
    {
        if (st[i].first >= st[j].first)
            return st[i];
        else
            return st[j];
    }
    void build(ll n, ll l, ll r)
    {
        if (l == r)
        {
            st[n].first = h[l];
            st[n].second = l;
            return;
        }
        ll m = (l + r) / 2;
        build(2 * n, l, m);
        build(2 * n + 1, m + 1, r);
        st[n] = merge(2 * n, 2 * n + 1);
    }
    ll query_update(ll n, ll l, ll r, ll val)
    {
        if (st[n].first < val)
            return 0;
        if (l == r)
        {
            st[n].first -= val;
            return st[n].second + 1;
        }
        ll m = (l + r) / 2;
        ll ans = 0;
        if (st[2 * n].first >= val)
            ans = query_update(2 * n, l, m, val);
        else
            ans = query_update(2 * n + 1, m + 1, r, val);
        st[n] = merge(2 * n, 2 * n + 1);
        return ans;
    }
    ll query(ll val)
    {
        return query_update(1, 0, n - 1, val);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n), r(m);
    for (auto &x : h)
        cin >> x;
    for (auto &x : r)
        cin >> x;
    SegTree seg(n, h);
    for (auto x : r)
        cout << seg.query(x) << " ";
    return 0;
}