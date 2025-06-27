// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define endl "\n"
// const ll mod = 1e9 + 7;
// ll n, m;
// vector<vector<char>> g;
// ll dp[510][510][510];
// ll rec(ll x1, ll y1, ll x2, ll y2)
// {
//     // prune case
//     if (x1 > x2 || y1 > y2)
//         return 0;
//     if (g[x1][y1] != g[x2][y2])
//         return 0;

//     // base case
//     ll len = (x1 - 1) + (y1 - 1) + (n - x2) + (m - y2);
//     if (len == ((n - 1) + (m - 1))) // odd length palindrome
//         return 1;
//     else if ((len + 1) == ((n - 1) + (m - 1))) // even length plaindrome
//         return 1;

//     if (dp[y1][x2][y2] != -1)
//         return dp[y1][x2][y2];

//     ll ans = 0;
//     ans = (ans + rec(x1, y1 + 1, x2 - 1, y2)) % mod;
//     ans = (ans + rec(x1, y1 + 1, x2, y2 - 1)) % mod;
//     ans = (ans + rec(x1 + 1, y1, x2 - 1, y2)) % mod;
//     ans = (ans + rec(x1 + 1, y1, x2, y2 - 1)) % mod;

//     return dp[y1][x2][y2] = ans;
// }
// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     cin >> n >> m;
//     g.resize(n + 1, vector<char>(m + 1));
//     for (ll i = 1; i <= n; i++)
//     {
//         for (ll j = 1; j <= m; j++)
//         {
//             cin >> g[i][j];
//         }
//     }

//     memset(dp, -1, sizeof(dp));
//     cout << rec(1, 1, n, m) % mod;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
vector<vector<char>> g;
ll dp[510][510][2];
ll get(ll x1, ll y1, ll x2, ll y2)
{
    if (x1 < 1 || x1 > n || y1 < 1 || y1 > m)
        return 0;
    if (x2 < 1 || x2 > n || y2 < 1 || y2 > m)
        return 0;
    if (g[x1][y1] != g[x2][y2])
        return 0;
    return dp[x1][x2][(x1 + y1) & 1];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1, vector<char>(m + 1));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));

    /*
        Formula for correlation:
            (x1 - 1) + (y1 - 1) = (n - x2) + (m - y2)
        so if :  (x1 - 1) + (y1 - 1) = d
        then  :  (n - x2) + (m - y2) = d
        now put the value of D in above formula
            (x2 - n) + (y2 - m) = - d
            (n - 1) + (m - 1) + (x2 - n) + (y2 - m) = D - d
            (x2 - 1) + (y2 - 1) = D - d
        given x2:
            y2 = n + m - x2 - d
        or  y2 = D - d + 2 - x2
    */
    const ll D = (n - 1) + (m - 1);
    ll lastLayer = D / 2;
    for (ll d = lastLayer; d >= 0; d--)
    {
        /* (x1 - 1) + (y1 - 1) = d */
        for (ll x1 = 1, y1 = d + 1; x1 <= n; x1++, y1--)
        {
            if (y1 < 1 || y1 > m)
                continue;

            /* (x2 - 1) + (y2 - 1) = D - d */
            for (ll x2 = n; x2 >= 1; x2--)
            {
                ll y2 = n + m - x2 - d;
                if (y2 < 1 || y2 > m)
                    continue;

                // mismatch in characters
                if (g[x1][y1] != g[x2][y2])
                {
                    dp[x1][x2][d & 1] = 0;
                    continue;
                }

                // middle of tha path in grid
                if (abs(x1 - x2) + abs(y1 - y2) <= 1)
                {
                    dp[x1][x2][d & 1] = 1;
                    continue;
                }

                ll ans = 0;
                ans = (ans + get(x1, y1 + 1, x2 - 1, y2)) % MOD;
                ans = (ans + get(x1, y1 + 1, x2, y2 - 1)) % MOD;
                ans = (ans + get(x1 + 1, y1, x2 - 1, y2)) % MOD;
                ans = (ans + get(x1 + 1, y1, x2, y2 - 1)) % MOD;

                dp[x1][x2][d & 1] = ans % MOD;
            }
        }
    }

    cout << get(1, 1, n, m);
    return 0;
}