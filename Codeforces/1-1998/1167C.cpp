#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n;
    vector<ll> sz, par;
    DSU(ll _n)
    {
        n = _n;
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
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (x > y)
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--)
    {
        ll k;
        cin >> k;
        if (k == 0)
            continue;
        ll u;
        cin >> u;
        for (ll i = 1; i < k; i++)
        {
            ll v;
            cin >> v;
            dsu.merge(u, v);
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << dsu.sz[dsu.find(i)] << " ";
    return 0;
}