#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll a[101];
// ll dp[101][101][101];
ll dp2[101][101][101];
// ll rec(ll l, ll r, ll x)
// {
//     if (l > r)
//         return 0;
//     if (dp[l][r][x] != -1)
//         return dp[l][r][x];

//     while (l < r && a[r] == a[r - 1])
//     {
//         r--;
//         x++;
//     }
//     dp[l][r][x] = rec(l, r - 1, 0) + (x + 1) * (x + 1);
//     for (int i = l; i < r; i++)
//     {
//         if (a[i] == a[r])
//         {
//             dp[l][r][x] = max(dp[l][r][x], rec(l, i, x + 1) + rec(i + 1, r - 1, 0));
//         }
//     }
//     return dp[l][r][x];
// }
ll rec2(ll l, ll r, ll x)
{
    if (l > r)
        return 0;
    if (dp2[l][r][x] != -1)
        return dp2[l][r][x];

    while (l < r && a[l] == a[l + 1])
    {
        l++;
        x++;
    }
    dp2[l][r][x] = rec2(l + 1, r, 0) + (x + 1) * (x + 1);
    for (ll i = l + 1; i <= r; i++)
    {
        if (a[l] == a[i])
        {
            dp2[l][r][x] = max(dp2[l][r][x], rec2(l + 1, i - 1, 0) + rec2(i, r, x + 1));
        }
    }
    return dp2[l][r][x];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // cout << rec(0, n - 1, 0) << endl;
    cout << rec2(0, n - 1, 0) << endl;
    return 0;
}