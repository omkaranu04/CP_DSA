#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll N, Q;
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
        // x is smaller
        if (x > y)
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
    }
    bool check(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        return x == y;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    DSU dsu(N);
    while (Q--)
    {
        ll t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            dsu.merge(u, v);
        if (t == 1)
            cout << (dsu.check(u, v) ? "1\n" : "0\n");
    }
    return 0;
}