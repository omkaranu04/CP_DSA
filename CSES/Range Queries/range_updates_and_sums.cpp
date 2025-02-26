#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, q;
vector<ll> t;
struct node
{
    ll l, r;
    ll sum;
    ll lazy_set; // set each element in the range to this value
    ll lazy_sum; // add this value to each element in the range
    node(ll l = 0, ll r = 0, ll sum = 0, ll lazy_set = 0, ll lazy_sum = 0) : l(l), r(r), sum(sum), lazy_set(lazy_set), lazy_sum(lazy_sum) {}
};
vector<node> segTree;
void merge(ll id)
{
    segTree[id].sum = segTree[2 * id].sum + segTree[2 * id + 1].sum;
}
void lazy_push(ll id)
{
    if (segTree[id].lazy_set)
    {
        segTree[id].sum = (segTree[id].r - segTree[id].l + 1) * segTree[id].lazy_set;
        if (segTree[id].l < segTree[id].r)
        {
            // left child
            segTree[2 * id].lazy_set = segTree[id].lazy_set;
            segTree[2 * id].lazy_sum = 0;
            // right child
            segTree[2 * id + 1].lazy_set = segTree[id].lazy_set;
            segTree[2 * id + 1].lazy_sum = 0;
        }
        segTree[id].lazy_set = 0;
    }
    if (segTree[id].lazy_sum)
    {
        segTree[id].sum += (segTree[id].r - segTree[id].l + 1) * segTree[id].lazy_sum;
        if (segTree[id].l < segTree[id].r)
        {
            segTree[2 * id].lazy_sum += segTree[id].lazy_sum;
            segTree[2 * id + 1].lazy_sum += segTree[id].lazy_sum;
        }
        segTree[id].lazy_sum = 0;
    }
}
void build(ll id, ll l, ll r)
{
    segTree[id].l = l;
    segTree[id].r = r;
    if (l == r)
    {
        segTree[id].sum = t[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    merge(id);
}
void update(ll id, ll l, ll r, ll ql, ll qr, ll val, bool set)
{
    lazy_push(id);
    if (l > qr || r < ql)
        return;
    if (l >= ql && r <= qr)
    {
        if (set)
        {
            segTree[id].lazy_set = val;
            segTree[id].lazy_sum = 0;
        }
        else
        {
            segTree[id].lazy_sum += val;
        }
        lazy_push(id);
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * id, l, mid, ql, qr, val, set);
    update(2 * id + 1, mid + 1, r, ql, qr, val, set);
    merge(id);
}
ll query(ll id, ll l, ll r, ll ql, ll qr)
{
    if (l > qr || r < ql)
        return 0;
    lazy_push(id);
    if (l >= ql && r <= qr)
        return segTree[id].sum;
    ll mid = (l + r) / 2;
    return query(2 * id, l, mid, ql, qr) + query(2 * id + 1, mid + 1, r, ql, qr);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    t.resize(n);
    segTree.resize(4 * n + 1);
    
    for (ll i = 0; i < n; i++)
        cin >> t[i];

    build(1, 0, n - 1);

    while (q--)
    {
        ll tt;
        cin >> tt;
        if (tt == 1)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            update(1, 0, n - 1, a - 1, b - 1, x, false);
        }
        else if (tt == 2)
        {
            ll a, b, x;
            cin >> a >> b >> x;
            update(1, 0, n - 1, a - 1, b - 1, x, true);
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }
    return 0;
}