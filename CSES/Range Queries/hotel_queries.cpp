#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<ll> h, r;
struct node
{
    ll max_room_in_seg;
    ll index;
};
vector<node> tree;
node merge(node a, node b)
{
    node temp;
    if (a.max_room_in_seg >= b.max_room_in_seg)
    {
        temp.max_room_in_seg = a.max_room_in_seg;
        temp.index = a.index;
    }
    else
    {
        temp.max_room_in_seg = b.max_room_in_seg;
        temp.index = b.index;
    }
    return temp;
}
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        tree[id].max_room_in_seg = h[l];
        tree[id].index = l + 1;
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
}
ll query(ll id, ll l, ll r, ll val)
{
    if (tree[id].max_room_in_seg < val)
        return 0;
    if (l == r)
    {
        tree[id].max_room_in_seg -= val;
        return tree[id].index;
    }

    ll mid = (l + r) / 2;
    int res;
    if (tree[2 * id].max_room_in_seg >= val)
        res = query(2 * id, l, mid, val);
    else
        res = query(2 * id + 1, mid + 1, r, val);

    tree[id] = merge(tree[2 * id], tree[2 * id + 1]);
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    h.resize(n);
    r.resize(m);
    tree.resize(4 * n + 1);

    for (ll i = 0; i < n; i++)
        cin >> h[i];
    for (ll i = 0; i < m; i++)
        cin >> r[i];

    build(1, 0, n - 1);
    for (ll i = 0; i < m; i++)
    {
        ll idx = query(1, 0, n - 1, r[i]);
        cout << idx << " ";
    }
    return 0;
}