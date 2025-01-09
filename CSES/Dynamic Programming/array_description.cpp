#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int MOD = 1e9 + 7;
int n, m;
vector<int> x;
vector<vector<int>> dp;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    x.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    dp.assign(n + 1, vector<int>(m + 1, 0));

    if (x[n] == 0)
    {
        for (int i = 1; i <= m; i++)
            dp[n][i] = 1;
    }
    else
    {
        dp[n][x[n]] = 1;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        if (x[i] == 0)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] += dp[i + 1][j];
                if (j - 1 > 0)
                    dp[i][j] += dp[i + 1][j - 1];
                if (j + 1 <= m)
                    dp[i][j] += dp[i + 1][j + 1];
                dp[i][j] %= MOD;
            }
        }
        else
        {
            dp[i][x[i]] += dp[i + 1][x[i]];
            if (x[i] - 1 > 0)
                dp[i][x[i]] += dp[i + 1][x[i] - 1];
            if (x[i] + 1 <= m)
                dp[i][x[i]] += dp[i + 1][x[i] + 1];
            dp[i][x[i]] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        ans = (ans + dp[1][i]) % MOD;
    cout << ans << endl;
    return 0;
}