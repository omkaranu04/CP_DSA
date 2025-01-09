#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll mod = 1e9 + 7;
ll n, m, k;
ll grid[205][205];
// number of ways to get to cell (r, c) with exactly rt consecutive rights
void solve()
{
    cin >> n >> m >> k;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    ll dp[n + 1][m + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    // reach (1, 1) w/o any right turn is 1 way
    if (grid[1][1] == 1)
    {
        cout << "0\n";
        return;
    }
    dp[1][1][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (grid[i][j] == 0)
            {
                for (ll l = 0; l <= k; l++)
                {
                    // upar se aao, upar bhale kitne right liye ho
                    dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j][l] % mod) % mod;
                    if (l > 0)
                    {
                        // right lete aao, from a cell to left
                        dp[i][j][l] = (dp[i][j][l] % mod + dp[i][j - 1][l - 1] % mod) % mod;
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i <= k; i++)
    {
        ans = (ans % mod + dp[n][m][i] % mod) % mod;
    }
    cout << ans << "\n";
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