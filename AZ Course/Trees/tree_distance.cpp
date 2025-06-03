#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, k, ans;
vector<vector<ll>> g, dp;
// dp[u][i] -> number of nodes at a distance i from u, in subtree rooted at u
void dfs(ll u, ll par)
{
    dp[u][0] = 1; // node u is at distance 0 from u itself
    for (auto v : g[u])
    {
        if (v != par)
        {
            dfs(v, u);

            for (ll i = 0; i < k; i++)
            {
                ans += dp[u][i] * dp[v][k - i - 1];
            }

            for (ll i = 1; i <= k; i++)
            {
                dp[u][i] += dp[v][i - 1];
            }
        }
    }
}
void solve()
{
    g.clear();
    dp.clear();

    cin >> n >> k;
    g.resize(n + 1);
    dp.resize(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans = 0;
    dfs(1, 0);
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}