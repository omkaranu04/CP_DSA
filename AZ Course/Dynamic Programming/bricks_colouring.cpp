#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, k;
void solve()
{
    cin >> n >> m >> k;
    int dp[n + 1][k + 1];
    memset(dp, 0, sizeof(dp));

    dp[1][0] = m; // 1 brick can be coloured m ways, 0 pattern has been followed till now
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j]; // same colour as previous brick
            if (j)
            {
                dp[i][j] = (dp[i][j] % mod + (dp[i - 1][j - 1] * 1LL * (m - 1) % mod)) % mod; // different colour from previous brick
            }
        }
    }
    cout << dp[n][k] % mod << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}