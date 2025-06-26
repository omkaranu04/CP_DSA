#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, q;
vector<vector<ll>> g;
vector<array<ll, 3>> queries, edges;
vector<ll> color;
struct DSU
{
    ll comps;
    vector<ll> par, sz;
    vector<set<ll>> col;
    DSU(ll n, vector<ll> &color) : comps(n), sz(n + 1, 1)
    {
        par.resize(n + 1);
        col.resize(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            par[i] = i;
            col[i].insert(color[i]);
        }
    }
    ll find(ll x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        col[x].insert(col[y].begin(), col[y].end());
        comps--;
    }
    ll distinctColors(ll x)
    {
        x = find(x);
        return col[x].size();
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    g.resize(n + 1);
    color.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> color[i];
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({i, u, v});
    }
    vector<ll> marked_edges(m, 0); // 1 if used in queries
    for (ll i = 1; i <= q; i++)
    {
        ll t, x;
        cin >> t >> x;
        queries.push_back({i, t, x});
        if (t == 1)
            marked_edges[x - 1] = 1;
    }

    DSU dsu(n, color);
    for (auto x : edges)
    {
        ll idx = x[0] - 1, u = x[1], v = x[2];
        if (marked_edges[idx] == 0)
            dsu.merge(u, v);
    }

    vector<ll> ans;
    for (ll i = q; i >= 1; i--)
    {
        auto x = queries[i - 1];
        ll idx = x[0], t = x[1], y = x[2];
        if (t == 1)
        {
            auto tmp = edges[y - 1];
            dsu.merge(tmp[1], tmp[2]);
        }
        else
        {
            ll tmp = dsu.distinctColors(y);
            ans.push_back(tmp);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << endl;
    return 0;
}