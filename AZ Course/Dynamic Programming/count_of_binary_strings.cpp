#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
vector<vector<int>> dp(1e6 + 1, vector<int>(5, -1));
int rec(int curr, int state)
{
    if (state == 4)
        return 0;
    if (curr == 0)
        return 1;

    if (dp[curr][state] != -1)
        return dp[curr][state];

    int ans = 0;
    if (state == 0)
    {
        ans = (ans % mod + rec(curr - 1, 0) % mod + rec(curr - 1, 1) % mod) % mod;
    }
    else if (state == 1)
    {
        ans = (ans % mod + rec(curr - 1, 1) % mod + rec(curr - 1, 2) % mod) % mod;
    }
    else if (state == 2)
    {
        ans = (ans % mod + rec(curr - 1, 3) % mod + rec(curr - 1, 0) % mod) % mod;
    }
    else if (state == 3)
    {
        ans = (ans % mod + rec(curr - 1, 4) % mod + rec(curr - 1, 2) % mod) % mod;
    }

    return dp[curr][state] = ans % mod;
}
void solve()
{
    cin >> n;
    // Recursive Approach values already calculated
    int ans = rec(n, 0);
    cout << ans << endl;

    // Iterative Approach
    // vector<vector<int>> dp;
    // dp.resize(n + 1, vector<int>(5, 0));
    // dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 1;
    // dp[0][4] = 0;

    // for (int i = 1; i <= n; i++)
    // {
    //     dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    //     dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
    //     dp[i][2] = (dp[i - 1][3] + dp[i - 1][0]) % mod;
    //     dp[i][3] = (dp[i - 1][4] + dp[i - 1][2]) % mod;
    //     dp[i][4] = 0;
    // }
    // cout << dp[n][0] << endl;
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