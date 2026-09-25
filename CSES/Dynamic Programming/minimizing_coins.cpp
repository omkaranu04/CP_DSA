#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 110, MAXX = 1e6 + 10;
ll N, X;
ll c[MAXN], dp[MAXX];
ll rec(ll rem)
{
    // base case
    if (rem == 0)
        return 0;
    // dp check and return
    if (dp[rem] != -1)
        return dp[rem];
    // transitions
    ll ans = LLONG_MAX;
    for (ll i = 1; i <= N; i++)
        if (rem - c[i] >= 0)
            if (rec(rem - c[i]) != LLONG_MAX)
                ans = min(ans, 1 + rec(rem - c[i]));
    // return
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
    cout << (rec(X) == LLONG_MAX ? -1 : rec(X));
    return 0;
}