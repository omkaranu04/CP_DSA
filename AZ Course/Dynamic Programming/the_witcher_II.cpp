#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> dungeon;
vector<vector<int>> dp;
int rec(int row, int col)
{
    if (row == n - 1 && col == m - 1)
        return max(1, 1 - dungeon[row][col]);
    if (row < 0 || col < 0 || row >= n || col >= m)
        return 1e9;

    if (dp[row][col] != -1)
        return dp[row][col];

    int t1 = rec(row + 1, col);
    int t2 = rec(row, col + 1);

    int ans = min(t1, t2) - dungeon[row][col];
    return dp[row][col] = max(1, ans);
}
void solve()
{
    cin >> n >> m;
    dungeon.clear();
    dp.clear();
    dungeon.resize(n, vector<int>(m));
    dp.resize(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dungeon[i][j];
        }
    }
    cout << rec(0, 0) << endl;
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