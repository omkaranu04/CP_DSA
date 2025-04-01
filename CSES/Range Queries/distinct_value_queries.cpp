#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct node
{
    ll sum;
};
ll n, q;
vector<ll> x, lastseen;
vector<pair<ll, ll>> f_lastseen;
vector<node> tree;
node merge(node a, node b)
{
    node temp;
    temp.sum = a.sum + b.sum;
    return temp;
}
void build(ll idx, ll l, ll r)
{
    if (l == r)
    {
        tree[idx].sum = 0;
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    return;
}
void update(ll idx, ll l, ll r, ll pos, ll val)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        tree[idx].sum = val;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * idx, l, mid, pos, val);
    update(2 * idx + 1, mid + 1, r, pos, val);
    tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
    return;
}
ll query(ll idx, ll l, ll r, ll ql, ll qr)
{
    if (l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
        return tree[idx].sum;
    ll mid = (l + r) / 2;
    return query(2 * idx, l, mid, ql, qr) + query(2 * idx + 1, mid + 1, r, ql, qr);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    x.resize(n);
    lastseen.resize(n, -1);
    tree.resize(4 * n + 1);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    map<ll, ll> mp;     
    for (ll i = 0; i < n; i++)
    {
        if (mp.find(x[i]) != mp.end())
            lastseen[i] = mp[x[i]];
        mp[x[i]] = i;
    }
    for (ll i = 0; i < n; i++)
    {
        f_lastseen.push_back({lastseen[i], i});
    }
    sort(f_lastseen.begin(), f_lastseen.end());

    // make the queries offline
    vector<pair<pair<ll, ll>, pair<ll, ll>>> queries; // k, query_idx, a, b
    vector<ll> ans(q);
    for (ll i = 0; i < q; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        queries.push_back({{a - 1, i}, {a, b}});
    }
    sort(queries.begin(), queries.end());

    // build function
    build(1, 0, n - 1);

    ll pos = 0;
    for (auto v : queries)
    {
        while (pos < f_lastseen.size() && f_lastseen[pos].first <= v.first.first)
        {
            // update function
            update(1, 0, n - 1, f_lastseen[pos].second, 1);
            pos++;
        }
        ans[v.first.second] = query(1, 0, n - 1, v.second.first, v.second.second); // query function
    }

    // final printing
    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}