#include <bits/stdc++.h>
using namespace std;
bool check(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    int win[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> win[i][j];
    }
    bool clean[n][m];
    int dp[n][m];
    memset(clean, false, sizeof(clean));
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // max kadhi paryant ghan pohochel
            if (check(i - 1, j - 1, n, m))
                dp[i][j] = max(dp[i - 1][j - 1], dp[i][j]);
            if (check(i - 1, j, n, m))
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            if (check(i - 1, j + 1, n, m))
                dp[i][j] = max(dp[i - 1][j + 1], dp[i][j]);

            if (win[i][j] >= dp[i][j])
            {
                clean[i][j] = true;
                dp[i][j] = win[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << clean[i][j];
        cout << endl;
    }
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