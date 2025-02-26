#include <bits/stdc++.h>
using namespace std;
int rec(int row, int col, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if (row < 0 || col < 0 || !a[row][col])
        return 0;

    if (dp[row][col] != -1)
        return dp[row][col];

    dp[row][col] = min({rec(row - 1, col, a, dp), rec(row, col - 1, a, dp), rec(row - 1, col - 1, a, dp)}) + 1;

    return dp[row][col];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, rec(i, j, a, dp));
        }
    }
    cout << ans * ans << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}