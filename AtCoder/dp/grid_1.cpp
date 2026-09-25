#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXH = 1010, MAXW = 1010;
ll H, W;
char g[MAXH][MAXW];
ll dp[MAXH][MAXW];
ll rec(ll i, ll j)
{
    // base case
    if (i == 1 && j == 1)
        return 1;
    if (i < 1 || i > H || j < 1 || j > W)
        return 0;
    if (g[i][j] == '#')
        return 0;
    // dp check and return
    if (dp[i][j] != -1)
        return dp[i][j];
    // transitions
    ll ans = 0;
    ans = (ans + rec(i - 1, j)) % MOD; // -> move down
    ans = (ans + rec(i, j - 1)) % MOD; // -> move up
    // return
    return dp[i][j] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> H >> W;
    for (ll i = 1; i <= H; i++)
        for (ll j = 1; j <= W; j++)
            cin >> g[i][j];
    cout << rec(H, W);
    return 0;
}