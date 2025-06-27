#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, M, B;
ll A[510];
ll dp[2][510][510];
// ll rec(ll i, ll line, ll bugs)
// {
//     if (line > M || bugs > B)
//         return 0;
//     if (i > N)
//     {
//         if (line == M && bugs <= B)
//             return 1;
//         return 0;
//     }

//     if (dp[i][line][bugs] != -1)
//         return dp[i][line][bugs];

//     ll ans = 0;
//     // ith coder writes 1 line
//     ans = (ans + rec(i, line + 1, bugs + A[i])) % mod;
//     // ith coder skips to next guy
//     ans = (ans + rec(i + 1, line, bugs)) % mod;

//     return dp[i][line][bugs] = ans % mod;
// }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> B;
    for (ll i = 1; i <= N; i++)
        cin >> A[i];

    // memset(dp, -1, sizeof(dp));
    // cout << rec(1, 0, 0);

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1; // 0 lines, 0 bugs

    for (ll i = 1; i <= N; i++)
    {
        ll p = i & 1, bugs = A[i];
        for (ll l = 0; l <= M; l++)
            memset(dp[p][l], 0, (B + 1) * sizeof(ll));

        for (ll l = 0; l <= M; l++)
        {
            for (ll b = 0; b <= B; b++)
            {
                // skip the coder
                dp[p][l][b] = (dp[p][l][b] + dp[p ^ 1][l][b]) % mod;
                // use the coder
                if (l && b >= bugs)
                    dp[p][l][b] = (dp[p][l][b] + dp[p][l - 1][b - bugs]) % mod;
            }
        }
    }
    ll ans = 0;
    for (ll b = 0; b <= B; b++)
        ans = (ans + dp[N & 1][M][b]) % mod;
    cout << ans << endl;
    return 0;
}