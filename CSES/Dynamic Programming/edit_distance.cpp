#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n, m;
vector<vector<int>> dp;
int solve(int i, int j)
{
    if (i == n && j == m)
        return 0;
    if (i == n)
        return m - j;
    if (j == m)
        return n - i;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = solve(i + 1, j + 1);

    // insert, delete, replace
    int temp = 1 + min({solve(i + 1, j), solve(i, j + 1), solve(i + 1, j + 1)});
    return dp[i][j] = temp;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    dp.resize(n + 1, vector<int>(m + 1, -1));
    cout << solve(0, 0) << endl;
    return 0;
}