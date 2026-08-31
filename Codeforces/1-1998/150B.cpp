#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
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
        if (sz[x] > sz[y])
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        comp--;
    }
};
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = modpow(a, b / 2);
    t = (t * 1LL * t) % MOD;
    if (b % 2)
        return (t * 1LL * a) % MOD;
    else
        return t;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    if (k > n)
    {
        cout << modpow(m, n);
        return 0;
    }

    DSU dsu(n);
    for (ll i = 0; i + k <= n; i++)
    {
        for (ll j = 0; j < k / 2; j++)
        {
            ll l = i + j;
            ll r = i + k - 1 - j;
            dsu.merge(l, r);
        }
    }
    cout << modpow(m, dsu.comp);
    return 0;
}