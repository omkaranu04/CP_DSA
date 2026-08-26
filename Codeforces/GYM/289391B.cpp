#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll N;
vector<ll> p;
struct DSU
{
    ll n;
    vector<ll> par, sz;
    DSU(ll _n)
    {
        n = _n;
        sz.resize(n + 2, 1);
        par.resize(n + 2);
        for (ll i = 0; i <= n + 1; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void park(ll x)
    {
        par[x] = find(x + 1);
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    p.resize(N + 1);
    for (ll i = 1; i <= N; i++)
        cin >> p[i];
    DSU dsu(N);
    for (ll i = 1; i <= N; i++)
    {
        ll x = dsu.find(p[i]);
        if (x == N + 1)
            x = dsu.find(1);
        cout << x << " ";
        dsu.park(x);
    }
    return 0;
}