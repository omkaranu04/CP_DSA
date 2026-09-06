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
    vector<Edge> edges(m);
    for (ll i = 0; i < m; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges.begin(), edges.end(), comp);
    ll ans = LLONG_MAX;
    for (ll l = 0; l < m; l++)
    {
        DSU dsu(n);
        for (ll r = l; r < m; r++)
        {
            dsu.unite(edges[r].u, edges[r].v);
            if (dsu.comp == 1)
            {
                ans = min(ans, edges[r].w - edges[l].w);
                break;
            }
        }
    }
    if (ans == LLONG_MAX)
        cout << "NO\n";
    else
        cout << "YES\n"
             << ans << endl;
    return 0;
}