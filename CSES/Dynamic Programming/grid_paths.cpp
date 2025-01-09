#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
ll n;
vector<string> grid;
vector<vector<ll>> dp;
ll rec(ll row, ll col)
{
    if (row == n - 1 && col == n - 1)
    {
        if (grid[row][col] == '.')
            return 1;
        return 0;
    }
    if (row >= n || col >= n || grid[row][col] == '*')
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    ll ans = 0;
    if (col + 1 < n && grid[row][col + 1] != '*')
        ans = (ans + rec(row, col + 1)) % mod;
    if (row + 1 < n && grid[row + 1][col] != '*')
        ans = (ans + rec(row + 1, col)) % mod;

    return dp[row][col] = ans;
}

ll rec2(ll row, ll col)
{
    if (row < 0 || col < 0 || grid[row][col] == '*')
        return 0;

    if (row == 0 && col == 0)
        return (grid[row][col] == '.') ? 1 : 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    ll ans = 0;
    ans = (ans + rec2(row - 1, col)) % mod;
    ans = (ans + rec2(row, col - 1)) % mod;

    return dp[row][col] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    grid.resize(n);
    dp.resize(n, vector<ll>(n, -1));
    for (ll i = 0; i < n; i++)
        cin >> grid[i];
    // cout << rec(0, 0) << endl;
    // dp.resize(n, vector<ll>(n, -1));
    cout << rec2(n - 1, n - 1) << endl;
    return 0;
}