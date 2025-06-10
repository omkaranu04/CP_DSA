#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
/*
    At each position (i, j) you have two choices for character s1[i]:
    Skip s1[i] entirely → the answer is rec(i−1, j).
    Take s1[i] as the first character of your uncommon subsequence:
    If s1[i] does not appear anywhere in s2[0..j], then simply picking s1[i] alone guarantees a subsequence of length 1 that s2 cannot match.
    Otherwise, suppose its last appearance in s2[0..j] is at position k. To remain uncommon, you must now find the rest of your subsequence in s1[0..i−1] that does not appear in s2[0..k−1], i.e. 1 + rec(i−1, k−1).
*/
// ll rec(ll i, ll j, vector<vector<ll>> &pre, vector<vector<ll>> &dp)
// {
//     if (i == -1)
//         return 1e18;
//     if (j == -1)
//         return 1; // base case you do not have anything to look in T
//     auto &ans = dp[i][j];
//     if (ans != -1)
//         return ans;
//     ans = rec(i - 1, j, pre, dp);
//     if (pre[i][j] == -1)
//         ans = 1;
//     else
//         ans = min(ans, 1 + rec(i - 1, pre[i][j] - 1, pre, dp));
//     return ans;
// }
void solve()
{
    string S, T;
    cin >> S >> T;
    ll m = S.length(), n = T.length();
    vector<vector<ll>> nextPos(n + 1, vector<ll>(26));
    /*
        nextPos[j][c] = next nearest index >= j in T where char c appears, if not -1
    */
    for (ll c = 0; c < 26; c++)
        nextPos[n][c] = -1;
    for (ll i = n - 1; i >= 0; i--)
    {
        nextPos[i] = nextPos[i + 1];
        nextPos[i][T[i] - 'a'] = i;
    }

    /*
        dp[i][j] = length of the shortest subsequence of S[i...] that is
                    NOT a subsequence of T[j...]
    */
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 1e18));
    // base case
    for (ll i = 0; i < m; i++)
        dp[i][n] = 1; // pick any char

    // fill bottom up
    for (ll i = m - 1; i >= 0; i--)
    {
        for (ll j = n - 1; j >= 0; j--)
        {
            // skip S[i]
            dp[i][j] = dp[i + 1][j];

            // take S[i]
            ll c = S[i] - 'a';
            ll p = nextPos[j][c];
            if (p == -1)
                dp[i][j] = 1;
            else
                dp[i][j] = min(dp[i][j], 1 + dp[i + 1][p + 1]);
        }
    }

    cout << ((dp[0][0] == 1e18) ? -1 : dp[0][0]) << endl;

    // vector<vector<ll>> pre(m, vector<ll>(n));
    // vector<vector<ll>> dp2(m + 1, vector<ll>(n + 1, -1));
    // for (ll i = 0; i < m; i++)
    // {
    //     ll p = -1;
    //     for (ll j = 0; j < n; j++)
    //     {
    //         if (S[i] == T[j])
    //             p = j;
    //         pre[i][j] = p;
    //     }
    // }

    // cout << ((rec(m - 1, n - 1, pre, dp2) > m) ? -1 : rec(m - 1, n - 1, pre, dp2)) << endl;
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