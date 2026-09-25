#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 3010;
ll dp[MAXN][MAXN];
ll n, m;
string s, t;
// what is the length of LCS starting at (i, j)
ll rec(ll i, ll j)
{
    // base case
    if (i >= n || j >= m)
        return 0;
    // dp check and return
    if (dp[i][j] != -1)
        return dp[i][j];
    // transition
    ll ans = 0;
    if (s[i] == t[j])
        ans = max(ans, 1 + rec(i + 1, j + 1));
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));
    // return
    return dp[i][j] = ans;
}
void lcs(ll i, ll j, string &ans)
{
    if (i >= n || j >= m)
        return;
    if (s[i] == t[j])
    {
        ans.push_back(s[i]);
        lcs(i + 1, j + 1, ans);
    }
    else
    {
        if (rec(i + 1, j) >= rec(i, j + 1))
            lcs(i + 1, j, ans);
        else
            lcs(i, j + 1, ans);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = s.length();
    m = t.length();
    ll lcs_len = rec(0, 0);
    string ans = "";
    lcs(0, 0, ans);
    cout << ans << endl;
    return 0;
}