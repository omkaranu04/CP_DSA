#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n;
int dp[41][41][41];
bool rec(int l1, int r1, int l2)
{
    int r2 = r1 + l2 - l1;
    if (l1 > r1 || l2 > r2)
        return false;

    if (dp[l1][r1][l2] != -1)
        return dp[l1][r1][l2];

    if (l1 == r1 || l2 == r2)
        return (s1[l1] == s2[l2]);

    if (s1.substr(l1, r1 - l1 + 1) == s2.substr(l2, r2 - l2 + 1))
        return true;

    bool ans = false;
    for (int i = l1; i < r1; i++)
    {
        // as it is
        ans |= rec(l1, i, l2) && rec(i + 1, r1, i + l2 - l1 + 1);
        // swap
        ans |= rec(l1, i, r1 + l2 - i) && rec(i + 1, r1, l2);
    }

    return dp[l1][r1][l2] = ans;
}
void solve()
{
    cin >> s1 >> s2;
    n = s1.length();
    memset(dp, -1, sizeof(dp));
    bool x = rec(0, n - 1, 0);
    if (x)
        cout << "Yes\n";
    else
        cout << "No\n";
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