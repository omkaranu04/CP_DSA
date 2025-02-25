#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<ll> x;
struct node
{
    ll total_sum, left_sum, right_sum, maxi;
};
vector<node> segTree;
node merge(node l, node r)
{
    node ans;
    ans.total_sum = l.total_sum + r.total_sum;
    ans.left_sum = max(l.left_sum, l.total_sum + r.left_sum);
    ans.right_sum = max(r.right_sum, r.total_sum + l.right_sum);
    ans.maxi = max(max(l.maxi, r.maxi), l.right_sum + r.left_sum);
    return ans;
}
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        segTree[id].total_sum = x[l];
        segTree[id].left_sum = x[l];
        segTree[id].right_sum = x[l];
        segTree[id].maxi = x[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    segTree[id] = merge(segTree[2 * id], segTree[2 * id + 1]);
}
void update(ll id, ll l, ll r, ll pos, ll val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        segTree[id].total_sum = val;
        segTree[id].left_sum = val;
        segTree[id].right_sum = val;
        segTree[id].maxi = val;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * id, l, mid, pos, val);
    update(2 * id + 1, mid + 1, r, pos, val);
    segTree[id] = merge(segTree[2 * id], segTree[2 * id + 1]);
}
ll query()
{
    return segTree[1].maxi;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    x.resize(n);
    segTree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    build(1, 0, n - 1);
    while (m--)
    {
        ll pos, val;
        cin >> pos >> val;
        update(1, 0, n - 1, pos - 1, val);
        cout << max(0LL, query()) << endl;
    }
    return 0;
}