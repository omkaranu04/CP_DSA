#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n, comp;
    vector<ll> par, sz;
    DSU(ll _n)
    {
        n = _n;
        comp = _n;
        sz.resize(n + 1, 1);
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool unite(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (sz[x] > sz[y])
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        comp--;
        return true;
    }
};
struct Edge
{
    ll u, v, w;
};
bool comp(Edge a, Edge b)
{
    return a.w < b.w;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &x : g)
        cin >> x;
    vector<vector<ll>> cost(n, vector<ll>(m, LLONG_MIN));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            string s = g[i], t = g[j];
            for (ll k = 0; k < m; k++)
            {
                ll diff = abs((s[k] - 'a') - (t[k] - 'a'));
                cost[i][j] = max(cost[i][j], diff);
                cost[j][i] = max(cost[j][i], diff);
            }
        }
    }

    vector<Edge> edges;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            edges.push_back({i, j, cost[i][j]});
        }
    }
    sort(edges.begin(), edges.end(), comp);

    DSU dsu(n);
    ll cnt = 0, ans = 0;
    for (auto e : edges)
    {
        if (dsu.unite(e.u, e.v))
        {
            ans = max(ans, e.w);
            cnt++;
            if (cnt == n - 1)
                break;
        }
    }
    cout << ans;
    return 0;
}