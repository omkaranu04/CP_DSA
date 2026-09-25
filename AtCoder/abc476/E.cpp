#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct Node
{
    ll mn, mx;
};
struct SegTree
{
    ll n;
    vector<ll> a;
    vector<Node> st;
    SegTree(const ll _n, const vector<ll> &_a)
    {
        n = _n;
        a = _a;
        st.resize(4 * n + 10);
        build(1, 0, n - 1);
    }
    Node merge(Node a, Node b)
    {
        Node c;
        c.mn = min(a.mn, b.mn);
        c.mx = max(a.mx, b.mx);
        return c;
    }
    void build(ll n, ll l, ll r)
    {
        if (l == r)
        {
            st[n].mn = a[l];
            st[n].mx = a[r];
            return;
        }
        ll m = (l + r) / 2;
        build(2 * n, l, m);
        build(2 * n + 1, m + 1, r);
        st[n] = merge(st[2 * n], st[2 * n + 1]);
    }
    void update(ll n, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            st[n].mn = val;
            st[n].mx = val;
            return;
        }
        ll m = (l + r) / 2;
        if (pos <= m)
            update(2 * n, l, m, pos, val);
        else
            update(2 * n + 1, m + 1, r, pos, val);
        st[n] = merge(st[2 * n], st[2 * n + 1]);
    }
    void update(ll pos, ll val)
    {
        update(1, 0, n - 1, pos, val);
    }
    Node query(ll n, ll l, ll r, ll ql, ll qr)
    {
        if (l > qr || r < ql)
            return {LLONG_MAX, LLONG_MIN};
        if (l >= ql && r <= qr)
            return st[n];
        ll m = (l + r) / 2;
        Node lft = query(2 * n, l, m, ql, qr);
        Node rgt = query(2 * n + 1, m + 1, r, ql, qr);
        return merge(lft, rgt);
    }
    Node query(ll l, ll r)
    {
        return query(1, 0, n - 1, l, r);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n), pos(n + 1);
    for (ll i = 0; i < n; i++)
    {
        cin >> p[i];
        pos[p[i]] = i;
    }
    SegTree seg(n, p);
    while (m--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        Node q = seg.query(l, r);
        ll mn = q.mn, mx = q.mx;
        ll pmn = pos[mn], pmx = pos[mx];
        swap(p[pmn], p[pmx]);
        pos[mn] = pmx;
        pos[mx] = pmn;
        seg.update(pmn, mx);
        seg.update(pmx, mn);
    }
    for (ll i = 0; i < n; i++)
        cout << p[i] << " ";
    cout << endl;
    return 0;
}