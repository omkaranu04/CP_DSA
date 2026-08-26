#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n;
    vector<ll> par, sz, add, diff;
    DSU(ll _n)
    {
        n = _n;
        par.resize(n + 1);
        sz.resize(n + 1, 1);
        add.resize(n + 1, 0);
        diff.resize(n + 1, 0);
        for (ll i = 0; i <= n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        ll p = par[x];
        par[x] = find(par[x]);
        diff[x] += diff[p];
        return par[x];
    }
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] > sz[y])
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        diff[x] = add[x] - add[y];
    }
    void addExp(ll x, ll v)
    {
        x = find(x);
        add[x] += v;
    }
    ll getExp(ll x)
    {
        ll xr = find(x);
        return add[xr] + diff[x];
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
        string t;
        cin >> t;
        if (t == "join")
        {
            ll x, y;
            cin >> x >> y;
            dsu.merge(x, y);
        }
        else if (t == "add")
        {
            ll x, v;
            cin >> x >> v;
            dsu.addExp(x, v);
        }
        else
        {
            ll x;
            cin >> x;
            cout << dsu.getExp(x) << endl;
        }
    }
    return 0;
}