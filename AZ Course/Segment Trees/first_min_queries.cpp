#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, q;
vector<ll> a;
vector<ll> segTree;
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        segTree[id] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    segTree[id] = max(segTree[2 * id], segTree[2 * id + 1]);
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        a[l] -= val;
        segTree[id] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    segTree[id] = max(segTree[2 * id], segTree[2 * id + 1]);
}
ll query(ll id, ll l, ll r, ll x)
{
    if (segTree[id] < x)
        return -1;
    if (l == r)
        return l;
    ll mid = (l + r) / 2;
    if (segTree[2 * id] >= x)
        return query(2 * id, l, mid, x);
    return query(2 * id + 1, mid + 1, r, x);
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
        ll x;
        cin >> x;
        ll idx = query(1, 0, n - 1, x);
        if (idx >= 0)
            update(1, 0, n - 1, idx, x);
        cout << idx + 1 << " ";
    }
    cout << "\n";
    return 0;
}