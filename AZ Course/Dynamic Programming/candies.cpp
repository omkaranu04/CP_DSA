#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k;
vector<int> a;
vector<vector<int>> dp, dp2;
int rec(int idx, int rem)
{
    if (rem < 0)
        return 0;
    if (idx == n)
        return (rem == 0);

    if (dp[idx][rem] != -1)
        return dp[idx][rem];

    int ans = 0;
    for (int i = 0; i <= a[idx]; i++)
    {
        ans = (ans % mod + rec(idx + 1, rem - i) % mod) % mod;
    }

    return dp[idx][rem] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp.resize(n + 1, vector<int>(k + 1, -1));
    // int ans = rec(0, k);
    // cout << ans << endl;

    dp2.resize(n + 1, vector<int>(k + 1, 0));
    for (int idx = n; idx >= 0; idx--)
    {
        for (int rem = 0; rem <= k; rem++)
        {
            if (idx == n)
            {
                dp2[idx][rem] = (rem == 0);
                continue;
            }
            // this can be further optimised by doing the uncommented part, prefix sum optimisation
            // for (int i = 0; i <= a[idx]; i++)
            // {
            //     dp2[idx][rem] = (dp[idx][rem] % mod + dp2[idx + 1][rem - i] % mod) % mod;
            // }
            dp2[idx][rem] = dp2[idx + 1][rem];
            if (rem - a[idx] >= 1)
            {
                dp2[idx][rem] = (dp2[idx][rem] - dp2[idx + 1][rem - a[idx] - 1] + mod) % mod;
            }
        }
        for (int i = 1; i <= k; i++)
        {
            dp2[idx][i] = (dp2[idx][i] % mod + dp2[idx][i - 1] % mod) % mod;
        }
    }
    // cout << dp2[0][k] << endl;
    cout << (dp2[0][k] - dp2[0][k - 1] + mod) % mod << endl;
    return 0;
}