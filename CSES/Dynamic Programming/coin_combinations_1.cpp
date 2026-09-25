#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 110, MAXX = 1e6 + 10;
ll N, c[MAXN], dp[MAXX], X;
ll rec(ll rem)
{
    if (rem == 0)
        return 1;
    if (dp[rem] != -1)
        return dp[rem];
    ll ans = 0;
    for (ll i = 1; i <= N; i++)
        if (rem - c[i] >= 0)
            ans = (ans + rec(rem - c[i])) % MOD;
    return dp[rem] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N >> X;
    for (ll i = 1; i <= N; i++)
        cin >> c[i];
    cout << rec(X);
    return 0;
}