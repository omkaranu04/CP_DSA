#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n, comp;
    vector<ll> sz, par;
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
    bool merge(ll x, ll y)
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
bool comp(Edge a, Edge b) { return a.w < b.w; }
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
    ll ans = 0;
    DSU dsu(n);
    for (ll i = 0; i < m; i++)
    {
        if (dsu.merge(edges[i].u, edges[i].v))
            ans += edges[i].w;
        if (dsu.comp == 1)
        {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}