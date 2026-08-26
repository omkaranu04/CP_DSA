#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n;
    vector<ll> dp, par;
    DSU(ll _n)
    {
        n = _n;
        par.resize(n + 1);
        dp.resize(n + 1, 0);
        for (ll i = 0; i <= n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        ll p = par[x];
        par[x] = find(par[x]);
        dp[x] += dp[p];
        return par[x];
    }
    void merge(ll a, ll b)
    {
        par[a] = b;
        dp[a] = 1;
    }
    ll getBoss(ll x)
    {
        ll px = find(x);
        return dp[x];
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
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll a, b;
            cin >> a >> b;
            dsu.merge(a, b);
        }
        else
        {
            ll c;
            cin >> c;
            cout << dsu.getBoss(c) << endl;
        }
    }
    return 0;
}