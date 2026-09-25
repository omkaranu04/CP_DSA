#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4000010;
const int M = 12;
ll dp[N][M];
ll modpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
ll solve(int i, int j)
{
    if (i == 0)
        return 1;
    if (j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll value = modpow(4, j);
    dp[i][j] = solve(i, j - 1);
    if (i >= value)
        dp[i][j] += solve(i - value, j);
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    while (T--)
    {
        int Y;
        cin >> Y;
        if (Y < 0 || Y >= N)
            cout << 0 << '\n';
        else
            cout << solve(Y, M - 1) << '\n';
    }
    return 0;
}