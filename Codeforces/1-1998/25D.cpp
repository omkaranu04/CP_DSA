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
        return true;
    }
};
struct Edge
{
    ll u, v;
};
struct Operation
{
    ll oldU, oldV;
    ll newU, newV;
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    DSU dsu(n);
    vector<Edge> red;
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (!dsu.merge(u, v))
            red.push_back({u, v});
    }
    vector<ll> rep;
    for (ll i = 1; i <= n; i++)
    {
        if (dsu.find(i) == i)
            rep.push_back(i);
    }
    cout << rep.size() - 1 << endl;
    ll mainRoot = rep[0];
    set<ll> rem;
    for (auto r : rep)
        if (r != mainRoot)
            rem.insert(r);
    for (auto edge : red)
    {
        ll comp = dsu.find(edge.u);
        if (rem.count(comp))
        {
            cout << edge.u << " " << edge.v << " " << edge.u << " " << mainRoot << " \n";
            rem.erase(comp);
        }
        else
        {
            ll other = *rem.begin();
            cout << edge.u << " " << edge.v << " " << edge.u << " " << other << " \n";
            rem.erase(other);
        }
    }
    return 0;
}