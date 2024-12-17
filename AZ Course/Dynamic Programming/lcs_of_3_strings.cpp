#include <bits/stdc++.h>
using namespace std;
int rec(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<vector<int>>> &dp)
{
    // base case / prune
    if (i == 0 || j == 0 || k == 0)
        return 0;

    // memoise
    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    // calculate
    if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1])
    {
        return dp[i][j][k] = (1 + rec(s1, s2, s3, i - 1, j - 1, k - 1, dp));
    }

    int ans = rec(s1, s2, s3, i - 1, j, k, dp);
    ans = max(ans, rec(s1, s2, s3, i, j - 1, k, dp));
    ans = max(ans, rec(s1, s2, s3, i, j, k - 1, dp));
    // ans = max(ans, rec(i - 1, j - 1, k));
    // ans = max(ans, rec(i - 1, j, k - 1));
    // ans = max(ans, rec(i, j - 1, k - 1));

    // return and save
    return dp[i][j][k] = ans;
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
        string s1, s2, s3;
        int l1, l2, l3;
        cin >> s1 >> s2 >> s3;
        l1 = s1.length();
        l2 = s2.length();
        l3 = s3.length();

        vector<vector<vector<int>>> dp(l1 + 1, vector<vector<int>>(l2 + 1, vector<int>(l3 + 1, -1)));

        int ans = rec(s1, s2, s3, l1, l2, l3, dp);
        cout << ans << endl;
    }
    return 0;
}