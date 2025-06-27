#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
const ll mod = 1e9 + 7;
/*
    f(i , j) = ways to distribute exactly j candies to the first i children.
    f(i+1 , j) = Σ_{c = 0 … min(ai , j)}  f(i , j − c)
    S(i , j) = Σ_{t = 0}^{j}  f(i , t)   (mod M)
    f(i+1 , j)  = S(i , j) − S(i , j − ai − 1)          (if j − ai − 1 ≥ 0)
                = S(i , j)                               otherwise

*/
ll N, K;
ll a[101];
// vector<vector<ll>> dp;
// ll rec(ll i, ll rem)
// {
//     if (rem == 0)
//         return 1;
//     if (i == N)
//         return rem == 0;
//     if (dp[i][rem] != -1)
//         return dp[i][rem];
//     ll ans = 0;
//     for (ll c = 0; c <= min(rem, a[i]); c++)
//     {
//         ans += rec(i + 1, rem - c);
//         if (ans >= mod)
//             ans -= mod;
//     }

//     return dp[i][rem] = ans;
// }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;

    for (ll i = 0; i < N; i++)
        cin >> a[i];

    // dp.resize(N + 1, vector<ll>(K + 1, -1));
    // cout << rec(0, K);

    vector<ll> dp(K + 1, 0);
    dp[0] = 1;
    for (ll child = 0; child < N; child++)
    {
        vector<ll> ps(K + 1);
        ps[0] = dp[0];
        for (ll i = 1; i <= K; i++)
        {
            ps[i] = ps[i - 1] + dp[i];
            if (ps[i] >= mod)
                ps[i] -= mod;
        }

        vector<ll> ndp(K + 1, 0);
        for (ll j = 0; j <= K; j++)
        {
            ll left = j - a[child] - 1;
            ll val = ps[j];
            if (left >= 0)
            {
                val -= ps[left];
                if (val < 0)
                    val += mod;
            }
            ndp[j] = val;
        }
        dp = ndp;
    }
    cout << dp[K];
    return 0;
}