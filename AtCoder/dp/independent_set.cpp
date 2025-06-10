#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<vector<ll>> g;
vector<ll> dp0, dp1; // white, black
void dfs(ll u, ll p)
{
    dp0[u] = 1;
    dp1[u] = 1;
    for (ll v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
            dp0[u] = (dp0[u] % mod * 1LL * (dp0[v] + dp1[v]) % mod) % mod;
            dp1[u] = (dp1[u] * 1LL * dp0[v]) % mod;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    dp0.resize(n + 1, 0);
    dp1.resize(n + 1, 0);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp0[1] + dp1[1]) % mod;
    return 0;
}