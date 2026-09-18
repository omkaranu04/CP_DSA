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
        build(1, 0, n - 1);
    }
    void build(ll n, ll l, ll r)
    {
        if (l == r)
        {
            st[n] = 1;
            return;
        }
        ll m = (l + r) / 2;
        build(2 * n, l, m);
        build(2 * n + 1, m + 1, r);
        st[n] = st[2 * n] + st[2 * n + 1];
    }
    void remove(ll n, ll l, ll r, ll pos)
    {
        if (l == r)
        {
            st[n] = 0;
            return;
        }
        ll m = (l + r) / 2;
        if (pos <= m)
            remove(2 * n, l, m, pos);
        else
            remove(2 * n + 1, m + 1, r, pos);
        st[n] = st[2 * n] + st[2 * n + 1];
    }
    void remove(ll pos)
    {
        remove(1, 0, n - 1, pos);
    }
    ll kth(ll n, ll l, ll r, ll k)
    {
        if (l == r)
            return l;
        ll m = (l + r) / 2;
        ll leftCnt = st[2 * n];
        if (k <= leftCnt)
            return kth(2 * n, l, m, k);
        else
            return kth(2 * n + 1, m + 1, r, k - leftCnt);
    }
    ll kth(ll pos)
    {
        return kth(1, 0, n - 1, pos);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> x(n), p(n);
    for (auto &xx : x)
        cin >> xx;
    for (auto &xx : p)
        cin >> xx;
    SegTree seg(n);
    for (auto &a : p)
    {
        ll idx = seg.kth(a);
        cout << x[idx] << " ";
        seg.remove(idx);
    }
    return 0;
}