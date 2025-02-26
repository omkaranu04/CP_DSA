#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
string s;
int n;
vector<vector<int>> dp;
int rec(int idx, int ps)
{
    if (ps < 0)
        return 0;
    if (idx == n)
        return (ps == 0);

    if (dp[idx][ps] != -1)
        return dp[idx][ps];

    if (s[idx] == '(')
        return dp[idx][ps] = rec(idx + 1, ps + 1) % mod;
    else if (s[idx] == ')')
        return dp[idx][ps] = rec(idx + 1, ps - 1) % mod;
    else
    {
        int ans = (rec(idx + 1, ps + 1) % mod + rec(idx + 1, ps - 1) % mod) % mod;
        return dp[idx][ps] = ans % mod;
    }
}
void solve()
{
    dp.clear();
    cin >> s;
    n = s.length();
    dp.resize(n + 1, vector<int>(n + 1, -1));
    int ans = rec(0, 0);
    cout << ans % mod << endl;
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