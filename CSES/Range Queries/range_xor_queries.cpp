#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, q;
vector<ll> a, segTree;
void build(ll index, ll l, ll r)
{
    if (l == r)
    {
        segTree[index] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    segTree[index] = segTree[2 * index] ^ segTree[2 * index + 1];
}
ll query(ll index, ll l, ll r, ll ql, ll qr)
{
    if (l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
        return segTree[index];
    ll mid = (l + r) / 2;
    return query(2 * index, l, mid, ql, qr) ^ query(2 * index + 1, mid + 1, r, ql, qr);
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
        ll l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(1, 0, n - 1, l, r) << endl;
    }
    return 0;
}