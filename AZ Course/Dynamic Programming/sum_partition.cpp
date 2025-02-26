#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define endl '\n'

const ll mod = 1e9 + 7;
ll dp[5001][5001];
ll rec(ll n, ll k)
{
    if (n == 0)
        return 1;
    if (n < 0 || k == 0)
        return 0;
    if (dp[n][k] != -1)
        return dp[n][k];

    ll ans = rec(n - k, k) % mod;
    ans = (ans % mod + rec(n, k - 1) % mod) % mod;

    return dp[n][k] = ans;
}
// void solve()
// {
//     memset(dp, 0LL, sizeof(dp));

//     dp[0][0] = 1;
//     for (int i = 1; i <= 5000; i++)
//     {
//         for (int j = 1; j <= 5000; j++)
//         {
//             dp[i][j] = dp[i - 1][j - 1];
//             if (i >= j)
//                 dp[i][j] = (dp[i][j] % mod + dp[i - j][j] % mod) % mod;
//         }
//     }
// }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    memset(dp, -1 * 1LL, sizeof(dp));
    // solve();
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        cout << rec(n - k, k) << endl;
    }
    return 0;
}