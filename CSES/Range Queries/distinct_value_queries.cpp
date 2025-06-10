#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, q;
vector<ll> x, last_seen;
vector<pair<ll, ll>> qs, llseen;
vector<pair<pair<ll, ll>, pair<ll, ll>>> offqs; // val, idx, l, r
struct SegTree
{
    ll n;
    vector<ll> a, st;
    SegTree(ll _n, vector<ll> &_a) : n(_n), a(_a), st(4 * _n + 4) {}
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
    ll query(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (l >= ql && r <= qr)
            return st[id];
        ll mid = (l + r) / 2;
        return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    x.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        qs.push_back({a, b});
    }

    last_seen.resize(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        if (mp.find(x[i]) == mp.end())
            last_seen[i] = -1;
        else
            last_seen[i] = mp[x[i]];
        mp[x[i]] = i;
    }

    ll tmp = 0;
    for (auto &[a, b] : qs)
    {
        offqs.push_back({{a - 1, tmp++}, {a, b}});
    }
    sort(offqs.begin(), offqs.end());

    for (ll i = 0; i < n; i++)
    {
        llseen.push_back({last_seen[i], i});
    }
    sort(llseen.begin(), llseen.end());

    vector<ll> a(n, 0), ans(q);
    SegTree st(n, a);
    ll j = 0;
    for (ll i = 0; i < q; i++)
    {
        auto &x = offqs[i];
        while (j < n && llseen[j].first <= x.first.first)
        {
            st.update(1, 0, n - 1, llseen[j].second, 1LL);
            j++;
        }
        ans[x.first.second] = st.query(1, 0, n - 1, x.second.first, x.second.second);
    }
    for (ll i = 0; i < q; i++)
        cout << ans[i] << endl;
    return 0;
}