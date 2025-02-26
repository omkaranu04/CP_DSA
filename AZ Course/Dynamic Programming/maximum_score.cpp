#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int rec(int r, int c, int k, int n, int m, vector<string> &score, int curr)
{
    // prune
    if (c < 0 || c >= m)
        return -1e9;

    // base case
    if (r == n)
    {
        if (curr == 0)
            return 0;
        return -1e9;
    }

    if (dp[r][c][curr] != -1)
        return dp[r][c][curr];

    int cell = score[r][c] - '0';
    cell = (curr + cell) % k;

    int ans = max(rec(r + 1, c - 1, k, n, m, score, cell), rec(r + 1, c + 1, k, n, m, score, cell));

    return dp[r][c][curr] = ans + (score[r][c] - '0');
}
int solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> score(n);
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = -1;
    for (int i = 0; i < m; i++)
    {
        ans = max(ans, rec(0, i, k, n, m, score, k));
    }
    return ans;
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
        cout << solve() << "\n";
    }
    return 0;
}