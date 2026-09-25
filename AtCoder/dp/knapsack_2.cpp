#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 110, MAXV = 100010;
ll N, W;
ll dp[MAXN][MAXV], w[MAXN], v[MAXN];
// What is the minimum weight required to get value 'rem_val' using items from i and ahead?
ll rec(ll i, ll rem_val)
{
    // base case
    if (rem_val == 0)
        return 0;
    // invalid state (since we desire min, return LLONG_MAX)
    if (i > N)
        return LLONG_MAX;
    // dp check and return
    if (dp[i][rem_val] != -1)
        return dp[i][rem_val];
    // transition
    // do not take item
    ll ans = rec(i + 1, rem_val);
    // take item
    if (rem_val >= v[i])
        if (rec(i + 1, rem_val - v[i]) != LLONG_MAX)
            ans = min(ans, rec(i + 1, rem_val - v[i]) + w[i]);
    // return
    return dp[i][rem_val] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N >> W;
    for (ll i = 1; i <= N; i++)
        cin >> w[i] >> v[i];
    ll ans = 0;
    for (ll v = 0; v < MAXV; v++)
        if (rec(1, v) <= W)
            ans = v;
    cout << ans;
    return 0;
}