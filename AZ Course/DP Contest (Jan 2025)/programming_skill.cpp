#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, k;
ll memo[10010], a[10010];
ll rec(ll i)
{
    if (i == 0)
        return 0;
    if (memo[i] != -1)
        return memo[i];
    ll ans = 0, currmax = 0;
    for (ll len = 1; len <= k && len <= i; len++)
    {
        currmax = max(currmax, a[i - len]);
        ans = max(ans, rec(i - len) + currmax * 1LL * len);
    }
    return memo[i] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> dp(n + 1, 0);
    // dp[i] -> maximum total skill we can obtain for first i children
    for (ll i = 1; i <= n; i++)
    {
        ll currmax = 0;
        for (ll len = 1; len <= k && len <= i; len++)
        {
            currmax = max(currmax, a[i - len]);
            dp[i] = max(dp[i], dp[i - len] + currmax * 1LL * len);
        }
    }
    // cout << dp[n];
    memset(memo, -1, sizeof(memo));
    cout << rec(n);
    return 0;
}