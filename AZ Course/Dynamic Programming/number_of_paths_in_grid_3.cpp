#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, k;
vector<vector<ll>> g;
ll dp[210][210][210];
ll rec(ll i, ll j, ll x)
{
    if (x > k)
        return 0;
    if (i >= n || j >= m)
        return 0;
    if (g[i][j] == 1)
        return 0;
    if (i == n - 1 && j == m - 1)
        return 1;
    if (dp[i][j][x] != -1)
        return dp[i][j][x];
    ll ans = 0;
    ans = (ans + rec(i + 1, j, 0)) % mod;
    ans = (ans + rec(i, j + 1, x + 1)) % mod;
    return dp[i][j][x] = ans;
}
void solve()
{
    g.clear();

    cin >> n >> m >> k;
    g.resize(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> g[i][j];

    // memset(dp, -1, sizeof(dp));
    // cout << rec(0, 0, 0) << endl;

    if (g[0][0] == 1)
    {
        cout << "0\n";
        return;
    }
    memset(dp, 0, sizeof(dp));
    for (ll x = 0; x <= k; x++)
        dp[n - 1][m - 1][x] = (g[n - 1][m - 1] == 0 ? 1 : 0);
    for (ll i = n - 1; i >= 0; i--)
    {
        for (ll j = m - 1; j >= 0; j--)
        {
            for (ll x = k; x >= 0; x--)
            {
                if (g[i][j] == 1)
                    continue;
                if (i == n - 1 && j == m - 1)
                    continue;
                ll ans = 0;
                if (i + 1 < n && g[i + 1][j] == 0)
                    ans = (ans + dp[i + 1][j][0]) % mod;
                if (j + 1 < m && g[i][j + 1] == 0 && x + 1 <= k)
                    ans = (ans + dp[i][j + 1][x + 1]) % mod;
                dp[i][j][x] = ans;
            }
        }
    }
    cout << dp[0][0][0] << endl;
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