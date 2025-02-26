#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int h, w;
vector<string> grid;
vector<vector<int>> dp;
int rec(int r, int c)
{
    if (r < 0 || c < 0 || r >= h || c >= w || grid[r][c] == '#')
        return 0;
    if (r == h - 1 && c == w - 1)
        return 1;

    if (dp[r][c] != -1)
        return dp[r][c];

    int ans = 0;
    if (r + 1 < h)
        ans = (ans % mod + rec(r + 1, c) % mod) % mod;
    if (c + 1 < w)
        ans = (ans % mod + rec(r, c + 1) % mod) % mod;

    return dp[r][c] = ans % mod;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    grid.resize(h);
    dp.resize(h + 1, vector<int>(w + 1, -1));
    for (int i = 0; i < h; i++)
        cin >> grid[i];

    cout << rec(0, 0) << endl;
    return 0;
}