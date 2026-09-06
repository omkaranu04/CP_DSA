#include <bits/stdc++.h>
using namespace std;
#define ll long long int
struct DSU
{
    ll n;
    vector<ll> sz, par, col;
    // col[x] = color[x] ^ color[root[x]]
    DSU(ll _n)
    {
        n = _n;
        sz.resize(n + 1, 1);
        par.resize(n + 1);
        iota(par.begin(), par.end(), 0);
        col.resize(n + 1, 0);
    }
    // returns {root, color[x] ^ color[root]}
    pair<ll, ll> find(ll x)
    {
        if (par[x] == x)
            return {x, 0};
        auto [root, p] = find(par[x]);
        /*
            we have -> col[x] = color[x] ^ color[par[x]]
            we have -> p = color[par[x]] ^ color[root]
            we want -> col[x] = color[x] ^ color[root]
            so -> col[x] ^= p => color[x] ^ color[root]
        */
        col[x] ^= p;
        par[x] = root;
        return {root, col[x]};
    }
    void merge(ll x, ll y)
    {
        auto [rx, px] = find(x);
        auto [ry, py] = find(y);
        if (rx == ry)
            return;
        /*
            px = color[x] ^ color[rx] => color[x] = px ^ color[rx]
            py = color[y] ^ color[ry] => color[y] = py ^ color[ry]
            we are adding edge (x, y) -> so we want color[x] ^ color[y] = 1
            => (px ^ color[rx]) ^ (py ^ color[ry]) = 1
            => color[rx] ^ color[ry] = 1 ^ px ^ py -> root color difference after joining the vertices
        */
        ll rootColorDiff = px ^ py ^ 1;
        if (sz[rx] < sz[ry])
        {
            par[rx] = ry;
            sz[ry] += sz[rx];
            col[rx] = rootColorDiff;
        }
        else
        {
            par[ry] = rx;
            sz[rx] += sz[ry];
            col[ry] = rootColorDiff;
        }
    }
    ll diff(ll x, ll y)
    {
        auto [rx, px] = find(x);
        auto [ry, py] = find(y);
        return px ^ py;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    DSU dsu(n);
    ll shift = 0;
    while (m--)
    {
        ll t, a, b;
        cin >> t >> a >> b;
        ll x = (a + shift) % n + 1;
        ll y = (b + shift) % n + 1;
        if (t == 0)
        {
            dsu.merge(x, y);
        }
        else
        {
            if (dsu.diff(x, y) == 0)
            {
                cout << "YES\n";
                shift = (shift + 1) % n;
            }
            else
                cout << "NO\n";
        }
    }
    return 0;
}