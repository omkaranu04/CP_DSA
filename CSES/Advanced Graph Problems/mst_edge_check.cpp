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
        for (ll i = 0; i <= n; i++)
            par[i] = i;
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
    ll idx;
    ll a, b, w;
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
    vector<bool> edgeUsed(m, false);
    DSU dsu(n);
    for (ll i = 0; i < m; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
        edges[i].idx = i;
    }
    sort(edges.begin(), edges.end(), comp);
    ll i = 0;
    while (i < m)
    {
        ll j = i;
        while (j < m && edges[j].w == edges[i].w)
            j++;
        for (ll k = i; k < j; k++)
        {
            ll u = edges[k].a, v = edges[k].b;
            if (dsu.find(u) != dsu.find(v))
                edgeUsed[edges[k].idx] = true;
        }
        for (ll k = i; k < j; k++)
            dsu.merge(edges[k].a, edges[k].b);
        i = j;
    }
    for (ll i = 0; i < m; i++)
        cout << (edgeUsed[i] ? "YES\n" : "NO\n");
    return 0;
}