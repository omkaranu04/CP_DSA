#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, q;
vector<ll> p;
struct node
{
    multiset<ll> ms;
};
vector<node> segTree;
node merge(node l, node r)
{
    node ans;
    ans.ms.insert(l.ms.begin(), l.ms.end());
    ans.ms.insert(r.ms.begin(), r.ms.end());
    return ans;
}
void build(ll id, ll l, ll r)
{
    if (l == r)
    {
        segTree[id].ms.insert(p[l]);
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    segTree[id] = merge(segTree[2 * id], segTree[2 * id + 1]);
}
void update(ll id, ll l, ll r, ll pos, ll oldval, ll newval)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        segTree[id].ms.erase(segTree[id].ms.find(oldval));
        segTree[id].ms.insert(newval);
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * id, l, mid, pos, oldval, newval);
    update(2 * id + 1, mid + 1, r, pos, oldval, newval);
    segTree[id] = merge(segTree[2 * id], segTree[2 * id + 1]);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    p.resize(n);
    segTree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    while (q--)
    {
        char type;
        cin >> type;
        if (type == '!')
        {
            ll k, x;
            cin >> k >> x;
            update(1, 0, n - 1, k - 1, p[k - 1], x);
            p[k - 1] = x;
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            auto it = segTree[1].ms.lower_bound(a);
            ll ans = 0;
            while (it != segTree[1].ms.end() && *it <= b)
            {
                ans++;
                it++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}