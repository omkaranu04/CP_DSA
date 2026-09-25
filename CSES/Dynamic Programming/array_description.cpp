#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll maxn = 100010, maxm = 110;
ll n, m;
ll x[maxn], dp[maxn][maxm];
ll rec(ll i, ll p)
{
    // base case
    if (i > n)
        return 1;
    // dp check and return
    if (dp[i][p] != -1)
        return dp[i][p];
    // transitions
    ll ans = 0;
    if (x[i] != 0)
    {
        if (llabs(p - x[i]) <= 1)
            ans = (ans + rec(i + 1, x[i])) % MOD;
    }
    else
    {
        for (ll d = 1; d <= m; d++)
        {
            if (llabs(p - d) <= 1)
                ans = (ans + rec(i + 1, d)) % MOD;
        }
    }
    // return
    return dp[i][p] = ans % MOD;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> x[i];

    // ll ans = 0;
    // if (x[1] == 0)
    // {
    //     for (ll d = 1; d <= m; d++)
    //         ans = (ans + rec(2, d)) % MOD;
    //     cout << ans % MOD;
    //     return 0;
    // }
    // ans = (ans + rec(2, x[1])) % MOD;
    // cout << ans % MOD;

    memset(dp, 0, sizeof(dp));
    if (x[1] != 0)
        dp[1][x[1]] = 1;
    else
        for (ll d = 1; d <= m; d++)
            dp[1][d] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (x[i] != 0)
        {
            dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]]) % MOD;
            if (x[i] - 1 >= 1)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % MOD;
            if (x[i] + 1 <= m)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % MOD;
        }
        else
        {
            for (ll d = 1; d <= m; d++)
            {
                dp[i][d] = dp[i - 1][d];
                if (d - 1 >= 1)
                    dp[i][d] = (dp[i][d] + dp[i - 1][d - 1]) % MOD;
                if (d + 1 <= m)
                    dp[i][d] = (dp[i][d] + dp[i - 1][d + 1]) % MOD;
            }
        }
    }
    ll ans = 0;
    for (ll d = 1; d <= m; d++)
        ans = (ans + dp[n][d]) % MOD;
    cout << ans % MOD << endl;
    return 0;
}