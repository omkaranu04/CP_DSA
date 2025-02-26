#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> grid;
int dx[] = {1, 0};
int dy[] = {0, 1};
int dp[51][51][51];
bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != -1;
}
int rec(int x1, int y1, int x2)
{
    int y2 = x1 + y1 - x2;
    if (!check(x1, y1) || !check(x2, y2))
    {
        return -1e9;
    }

    if (x1 == n - 1 && y1 == n - 1 && x2 == n - 1 && y2 == n - 1)
    {
        return grid[x1][y1];
    }

    if (dp[x1][y1][x2] != -1)
    {
        return dp[x1][y1][x2];
    }

    int ans = -1e9, val;

    if (x1 == x2 && y1 == y2)
        val = grid[x1][y1];
    else
        val = grid[x1][y1] + grid[x2][y2];

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[j];
            int ny2 = y2 + dy[j];

            ans = max(ans, val + rec(nx1, ny1, nx2));
        }
    }

    return dp[x1][y1][x2] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    grid.resize(n, vector<int>(n));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result = rec(0, 0, 0);
    cout << (result < 0 ? 0 : result) << endl;
    return 0;
}