#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 110;
const ll MAXW = 100010;
ll N, W;
ll dp[MAXN][MAXW], w[MAXN], v[MAXN];
ll rec(ll i, ll rem)
{
    // base case
    if (i > N)
        return 0;
    // dp check and return
    if (dp[i][rem] != -1)
        return dp[i][rem];
    // transition
    ll ans = 0;
    ans = max(ans, rec(i + 1, rem)); // -> not take item
    if (rem >= w[i])
        ans = max(ans, rec(i + 1, rem - w[i]) + v[i]); // -> take item
    // return
    return dp[i][rem] = ans;
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
    cout << rec(1, W);
    return 0;
}