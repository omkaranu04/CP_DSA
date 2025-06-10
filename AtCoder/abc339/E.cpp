#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll MAX = 500500;
ll N, D;
vector<ll> A;
struct SegTree
{
    ll n;
    vector<ll> st;
    SegTree(ll _n) : n(_n), st(4 * _n + 4, 0) {}
    void update(ll id, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[id] = max(st[id], val);
            return;
        }
        ll mid = (l + r) / 2;
        if (pos <= mid)
            update(2 * id, l, mid, pos, val);
        else
            update(2 * id + 1, mid + 1, r, pos, val);
        st[id] = max(st[2 * id], st[2 * id + 1]);
    }
    ll query(ll id, ll l, ll r, ll ql, ll qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return st[id];
        ll mid = (l + r) / 2;
        return max(query(2 * id, l, mid, ql, qr), query(2 * id + 1, mid + 1, r, ql, qr));
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> D;
    A.resize(N);
    for (ll i = 0; i < N; i++)
        cin >> A[i];

    SegTree st(MAX);
    ll ans = 0;

    for (ll i = 0; i < N; i++)
    {
        ll ql = max(0LL, A[i] - D);
        ll qr = min(MAX, A[i] + D);

        ll prev = st.query(1, 0, MAX - 1, ql, qr);
        ll curr = prev + 1;
        st.update(1, 0, MAX - 1, A[i], curr);
        ans = max(ans, curr);
    }
    cout << ans;
    return 0;
}