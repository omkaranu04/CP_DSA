#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
// ll rec(ll i, ll j)
// {
//     if (i == l1 || j == l2)
//         return 0;
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     ll ans = 0;
//     if (s1[i] == s2[j])
//         ans = max(ans, 1LL + rec(i + 1, j + 1));
//     else
//         ans = max(rec(i + 1, j), rec(i, j + 1));
//     return dp[i][j] = ans;
// }
string ShortestCommonSupersequence(string &s1, string &s2)
{
    ll l1 = s1.length(), l2 = s2.length();
    ll dp[l1 + 1][l2 + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = l1; i >= 0; i--)
    {
        for (ll j = l2; j >= 0; j--)
        {
            if (i == l1 || j == l2)
                continue;

            ll ans = 0;
            if (s1[i] == s2[j])
                ans = 1LL + dp[i + 1][j + 1];
            else
                ans = max(dp[i + 1][j], dp[i][j + 1]);

            dp[i][j] = ans;
        }
    }

    ll lcslen = dp[0][0];
    string ans = "";
    ll i = 0, j = 0;
    while (i < l1 && j < l2)
    {
        if (s1[i] == s2[j])
        {
            ans.push_back(s1[i]);
            i++, j++;
        }
        else if (dp[i + 1][j] >= dp[i][j + 1])
        {
            ans.push_back(s1[i]);
            i++;
        }
        else
        {
            ans.push_back(s2[j]);
            j++;
        }
    }
    while (i < l1)
        ans.push_back(s1[i++]);
    while (j < l2)
        ans.push_back(s2[j++]);
    return ans;
}

void checker()
{
    string x, y;
    cin >> x >> y;
    auto s = ShortestCommonSupersequence(x, y);
    cout << s.size() << endl;
    bool f = 1;
    int i = 0, j = 0;
    while (i < x.size() && j < s.size())
    {
        if (x[i] == s[j])
            i++, j++;
        else
            j++;
    }
    if (i != x.size())
        f = 0;
    i = 0, j = 0;
    while (i < y.size() && j < s.size())
    {
        if (y[i] == s[j])
            i++, j++;
        else
            j++;
    }
    if (i != y.size())
        f = 0;
    cout << f << endl;
}
int main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        checker();
        // i++;
    }
    return 0;
}