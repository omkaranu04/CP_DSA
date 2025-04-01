#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, q;
vector<ll> a, b;
struct node
{
    ll sum;
};
vector<node> segTree;
node merge(node l, node r)
{
    node res;
    res.sum = l.sum + r.sum;
    return res;
}
void build(ll node, ll l, ll r)
{
    if (l == r)
    {
        segTree[node].sum = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    segTree[node] = merge(segTree[2 * node], segTree[2 * node + 1]);
}
void update(ll node, ll l, ll r, ll idx, ll val)
{
    if (l == r)
    {
        segTree[node].sum = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid)
        update(2 * node, l, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, r, idx, val);
    segTree[node] = merge(segTree[2 * node], segTree[2 * node + 1]);
    return;
}
ll query(ll node, ll l, ll r, ll ql, ll qr)
{
    if (qr < l || ql > r)
        return 0;
    if (ql <= l && qr >= r)
        return segTree[node].sum;
    ll mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    b.resize(n);
    segTree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];

    // build seg tree for a
    build(1, 0, n - 1);

    // store all >= 2 elements of b
    set<ll> setB;
    for (ll i = 0; i < n; i++)
    {
        if (b[i] >= 2)
            setB.insert(i);
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll i, x;
            cin >> i >> x;
            i--;
            a[i] = x;
            update(1, 0, n - 1, i, x);
        }
        if (t == 2)
        {
            ll i, x;
            cin >> i >> x;
            i--;
            if (b[i] >= 2)
                setB.erase(i);
            b[i] = x;
            if (b[i] >= 2)
                setB.insert(i);
        }
        if (t == 3)
        {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            ll v = a[l];
            while (l < r)
            {
                auto it = setB.lower_bound(l + 1);
                ll next_l;

                if (it != setB.end() && *it <= r)
                {
                    next_l = *it;
                    if (l + 1 <= next_l - 1)
                        v += query(1, 0, n - 1, l + 1, next_l - 1);
                    v = max(v + a[next_l], v * b[next_l]);
                }
                else
                {
                    if (l + 1 <= r)
                        v += query(1, 0, n - 1, l + 1, r);
                    break;
                }
                l = next_l;
            }

            cout << v << endl;
        }
    }
    return 0;
}