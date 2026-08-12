#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
struct SegTree
{
    ll n;
    vector<ll> cntTree, sumTree;
    SegTree(ll _n) : n(_n), cntTree(4 * _n + 4, 0), sumTree(4 * _n + 4, 0) {}
    void update(ll id, ll l, ll r, ll pos, ll val, ll cnt)
    {
        if (l == r)
        {
            cntTree[id] += cnt;
            sumTree[id] += val;
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * id, l, mid, pos, val, cnt);
        else
            update(2 * id + 1, mid + 1, r, pos, val, cnt);
        cntTree[id] = cntTree[2 * id] + cntTree[2 * id + 1];
        sumTree[id] = sumTree[2 * id] + sumTree[2 * id + 1];
    }
    pair<ll, ll> query(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return {0, 0};
        if (ql <= l && r <= qr)
            return {cntTree[id], sumTree[id]};
        ll mid = (l + r) / 2;
        auto lquery = query(2 * id, l, mid, ql, qr);
        auto rquery = query(2 * id + 1, mid + 1, r, ql, qr);
        return {lquery.first + rquery.first, lquery.second + rquery.second};
    }
};
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> ps(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + (s[i - 1] == '1' ? 1 : -1);
    }
    vector<ll> vals = ps;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    ll m = vals.size();
    SegTree st(m);

    ll S = 0;
    for (ll i = 0; i <= n; i++)
    {
        ll idx = lower_bound(vals.begin(), vals.end(), ps[i]) - vals.begin();
        auto [cntl, suml] = st.query(1, 1, m, 1, idx);
        auto [totcnt, totsum] = st.query(1, 1, m, 1, m);
        S += ps[i] * cntl - suml + (totsum - suml) - ps[i] * (totcnt - cntl);
        st.update(1, 1, m, idx, ps[i], 1);
    }
    ll totlen = n * 1LL * (n + 1) * 1LL * (n + 2) / 6;
    ll ans = (totlen + S) / 2;
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}