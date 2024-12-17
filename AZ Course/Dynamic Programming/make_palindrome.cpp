#include <bits/stdc++.h>
using namespace std;
string s;
vector<vector<int>> dp;
int n;
int rec(int i, int j)
{
    if (i == -1)
        return n - j;
    if (j == n)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = 1e9;
    if (s[i] == s[j])
        ans = min(ans, rec(i - 1, j + 1));
    else
        ans = min({ans, rec(i - 1, j) + 1, rec(i, j + 1) + 1});

    return dp[i][j] = ans;
}
void solve()
{
    dp.clear();
    cin >> s;
    n = s.length();
    dp.resize(n + 1, vector<int>(n + 1, -1));
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min({ans, rec(i - 1, i + 1), rec(i - 1, i), rec(i, i + 1)});
    }
    cout << ans << endl;
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