#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, q;
vector<ll> a;
struct node
{
    ll even, odd;
    node()
    {
        even = 0;
        odd = 0;
    }
};
vector<node> tree;
node merge(node a, node b)
{
    node ans;
    ans.even = a.even + b.even;
    ans.odd = a.odd + b.odd;
    return ans;
}
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        if (a[l] % 2 == 0)
            tree[id].even = 1;
        else
            tree[id].odd = 1;
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        if (val % 2)
        {
            tree[id].odd = 1;
            tree[id].even = 0;
        }
        else
        {
            tree[id].odd = 0;
            tree[id].even = 1;
        }
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
}
node query(ll id, ll l, ll r, ll ql, ll qr)
{
    if (l > qr || r < ql)
        return node();
    if (l >= ql && r <= qr)
        return tree[id];
    ll mid = (l + r) / 2;
    node left = query(2 * id, l, mid, ql, qr);
    node right = query(2 * id + 1, mid + 1, r, ql, qr);
    return merge(left, right);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    tree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 0)
        {
            ll x, y;
            cin >> x >> y;
            x--;
            update(1, 0, n - 1, x, y);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--, r--;
            node ans = query(1, 0, n - 1, l, r);
            if (t == 1)
                cout << ans.even << endl;
            else
                cout << ans.odd << endl;
        }
    }
    return 0;
}