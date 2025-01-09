#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string s, t;
ll n, m;
vector<vector<ll>> dp;
ll rec(ll i, ll j)
{
    // prune
    // base case
    if (i == 0 || j == 0)
        return 0;

    // memoise
    if (dp[i][j] != -1)
        return dp[i][j];

    // calculate

    if (s[i - 1] == t[j - 1])
        return 1 + rec(i - 1, j - 1);

    ll ans = rec(i - 1, j);
    ans = max(ans, rec(i, j - 1));

    // store and return
    return dp[i][j] = ans;
}
string retrieve_string(ll i, ll j)
{
    if (i == 0 || j == 0)
        return "";
    if (s[i - 1] == t[j - 1])
        return s[i - 1] + retrieve_string(i - 1, j - 1);

    if (rec(i - 1, j) > rec(i, j - 1))
        return retrieve_string(i - 1, j);
    else
        return retrieve_string(i, j - 1);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s >> t;
    n = s.size();
    m = t.size();
    dp.resize(n + 1, vector<ll>(m + 1, -1));
    ll ans = rec(n, m);
    string llccss = retrieve_string(n, m);
    reverse(llccss.begin(), llccss.end());
    // cout << ans << endl;
    cout << llccss << endl;
    return 0;
}