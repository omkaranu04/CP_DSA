#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MAXN = 100010;
ll N;
ll dp[MAXN][4];
ll a[MAXN], b[MAXN], c[MAXN];
// starting at day i, previously doing activity prev
ll rec(ll i, ll prev)
{
    // base case -> (i > N has no contribution)
    if (i > N)
        return 0;
    // dp check and return
    if (dp[i][prev] != -1)
        return dp[i][prev];
    // transition
    ll ans = 0;
    if (prev != 1)
        ans = max(ans, rec(i + 1, 1) + a[i]);
    if (prev != 2)
        ans = max(ans, rec(i + 1, 2) + b[i]);
    if (prev != 3)
        ans = max(ans, rec(i + 1, 3) + c[i]);
    // return
    return dp[i][prev] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (ll i = 1; i <= N; i++)
        cin >> a[i] >> b[i] >> c[i];
    cout << rec(1, 0);
    return 0;
}