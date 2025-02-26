#include <bits/stdc++.h>
using namespace std;
int rec(int i, int j, string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + rec(i - 1, j - 1, s1, s2, n, m, dp);
    }
    return dp[i][j] = 0;
}
void solve()
{
    string s1, s2;
    int n, m;
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    // int dp[n + 1][m + 1];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int ans = 0;
    // memset(dp, -1, sizeof(dp));
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         if (s1[i - 1] == s2[j - 1])
    //         {
    //             dp[i][j] = 1 + dp[i - 1][j - 1];
    //         }
    //         else
    //         {
    //             dp[i][j] = 0;
    //         }
    //         ans = max(ans, dp[i][j]);
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, rec(i, j, s1, s2, n, m, dp));
        }
    }
    cout << ans << endl;
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