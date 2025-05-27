#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> g;
vector<ll> dp;
ll dfs(ll u)
{
    if (dp[u] != -1)
        return dp[u];
    ll ans = 0;
    for (auto v : g[u])
    {
        ans = max(ans, 1 + dfs(v));
    }
    return dp[u] = ans;
}
int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    dp.resize(n + 1, -1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans = max(ans, dfs(i));
    cout << ans << endl;
}