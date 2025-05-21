#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct segTree
{
    ll n;
    vector<ll> st;
    segTree(ll n) : n(n), st(4 * n + 4, 0) {}
    void update(ll idx, ll val, ll node, ll l, ll r)
    {
        if (l == r)
        {
            st[node] += val;
            return;
        }
        ll mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node, l, mid);
        else
            update(idx, val, 2 * node + 1, mid + 1, r);
        st[node] = st[2 * node] + st[2 * node + 1];
    }
    void update(ll idx, ll val)
    {
        update(idx, val, 1, 1, n);
    }
    ll query(ll l, ll r, ll idx, ll tl, ll tr)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return st[idx];
        ll mid = (tl + tr) / 2;
        return query(l, min(r, mid), 2 * idx, tl, mid) + query(max(l, mid + 1), r, 2 * idx + 1, mid + 1, tr);
    }
    ll query(ll l, ll r)
    {
        return query(l, r, 1, 1, n);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<ll> u(n), v(n);
    for (ll i = 1; i < n; i++)
    {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back({v[i], i});
        adj[v[i]].push_back({u[i], i});
    }
    vector<ll> tin(n + 1), tout(n + 1), chedge(n);
    ll timer = 0;
    vector<array<ll, 3>> stk;
    stk.push_back({1, 0, 0});
    while (!stk.empty())
    {
        auto &f = stk.back();
        ll u = f[0], p = f[1], &ci = f[2];
        if (ci == 0)
            tin[u] = ++timer;
        if (ci < adj[u].size())
        {
            auto [v, eid] = adj[u][ci++];
            if (v == p)
                continue;
            chedge[eid] = v;
            stk.push_back({v, u, 0});
        }
        else
        {
            tout[u] = timer;
            stk.pop_back();
        }
    }

    segTree st(n);
    for (ll i = 1; i <= n; i++)
        st.update(tin[i], 1);

    ll q;
    cin >> q;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x, w;
            cin >> x >> w;
            st.update(tin[x], w);
        }
        else
        {
            ll y;
            cin >> y;
            ll tmp = chedge[y];
            ll sub = st.query(tin[tmp], tout[tmp]);
            ll tot = st.query(1, n);
            cout << abs(sub - (tot - sub)) << endl;
        }
    }
    return 0;
}