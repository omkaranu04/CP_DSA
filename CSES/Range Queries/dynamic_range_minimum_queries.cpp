#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, q;
vector<ll> a, segTree;
void build(ll index, ll l, ll r)
{
    if (l == r)
    {
        // base case you arrive at the leaf
        segTree[index] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    // halve and call the left and right child
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);

    // after left and right update the current node
    segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
}
void update(ll index, ll l, ll r, ll i, ll x)
{
    if (l == r)
    {
        segTree[index] = x;
        return;
    }
    ll mid = (l + r) / 2;
    if (i <= mid)
        update(2 * index, l, mid, i, x);
    else
        update(2 * index + 1, mid + 1, r, i, x);
    segTree[index] = min(segTree[2 * index], segTree[2 * index + 1]);
    return;
}
ll query(ll index, ll l, ll r, ll ql, ll qr)
{
    if (l > qr || r < ql)
        return 1e18;
    if (l >= ql && r <= qr)
        return segTree[index];
    ll mid = (l + r) / 2;
    return min(query(2 * index, l, mid, ql, qr), query(2 * index + 1, mid + 1, r, ql, qr));
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    a.resize(n);
    segTree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll i, x;
            cin >> i >> x;
            i--;
            update(1, 0, n - 1, i, x);
        }
        else if (t == 2)
        {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            // cout << "Ans : ";
            cout << query(1, 0, n - 1, l, r) << endl;
        }
    }
    return 0;
}