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
    ll lazy_sum;
    node(ll l = 0, ll r = 0, ll sum = 0, ll lazy_sum = 0) : l(l), r(r), sum(sum), lazy_sum(lazy_sum) {}
};
vector<node> segTree;
void merge(ll id)
{
    segTree[id].sum = segTree[2 * id].sum + segTree[2 * id + 1].sum;
}
void lazy_push(ll id)
{
    if(segTree[id].lazy_sum)
    {
        ll temp = segTree[id].r - segTree[id].l + 1;
        segTree[id].sum += (temp * (temp + 1) / 2) * segTree[id].lazy_sum;
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
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    t.resize(n);
    segTree.resize(4 * n);
    for (ll i = 0; i < n; i++)
        cin >> t[i];
    return 0;
}