#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 505, MAXM = 64000;
ll N, dp[MAXN][MAXM];
ll rec(ll d, ll r)
{
    if (r == 0)
        return 1;
    if (dp[d][r] != -1)
        return dp[d][r];
    ll ans = 0;
    // not take
    if (d + 1 <= N)
        ans += rec(d + 1, r);
    // take
    if (d + 1 <= N && r - d >= 0)
        ans += rec(d + 1, r - d);
    return dp[d][r] = ans % MOD;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    ll s = (N * (N + 1)) / 2;
    if (s % 2)
        cout << 0;
    else
    {
        ll s2 = s / 2;
        cout << rec(1, s2) % MOD;
    }
    return 0;
}