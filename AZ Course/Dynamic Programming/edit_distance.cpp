#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n, m;
vector<vector<int>> dp;
int rec(int i, int j)
{
    if (i == 0 && j == 0)
        return 0;
    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (dp[i][j] != -1)
        return dp[i][j];

    // if current characters are same, no need to do anything
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = rec(i - 1, j - 1);

    // if current characters are different, we can either insert, delete or replace
    return dp[i][j] = (1 + min({rec(i - 1, j), rec(i, j - 1), rec(i - 1, j - 1)}));
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
    cout << rec(n, m) << endl;
    return 0;
}