#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, m, k;
vector<vector<int>> grid;
vector<vector<vector<int>>> dp;
int rec(int row, int col, int can_be_unblocked)
{
    if (row < 0 || col < 0 || row >= n || col >= m || can_be_unblocked < 0)
        return 0;

    if (dp[row][col][can_be_unblocked] != -1)
        return dp[row][col][can_be_unblocked];

    if (row == n - 1 && col == m - 1)
    {
        if (grid[row][col] == 1 && can_be_unblocked > 0)
            return 1;
        if (grid[row][col] == 0)
            return 1;
        return 0;
    }

    int ans = 0;
    if (grid[row][col] == 1)
    {
        ans = (rec(row + 1, col, can_be_unblocked - 1) % mod + rec(row, col + 1, can_be_unblocked - 1) % mod) % mod;
    }
    else
    {
        ans = (rec(row + 1, col, can_be_unblocked) % mod + rec(row, col + 1, can_be_unblocked) % mod) % mod;
    }

    return dp[row][col][can_be_unblocked] = ans % mod;
}
void solve()
{
    cin >> n >> m >> k;
    grid.clear();
    dp.clear();
    grid.resize(n, vector<int>(m));
    dp.resize(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cout << rec(0, 0, k) << endl;
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