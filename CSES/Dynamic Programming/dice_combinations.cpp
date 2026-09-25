#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 10;
ll N;
ll dp[MAXN];
ll rec(ll rem)
{
    // base case
    if (rem == 0)
        return 1;
    // dp check and return
    if (dp[rem] != -1)
        return dp[rem];
    // transitions
    ll ans = 0;
    for (ll i = 1; i <= 6; i++)
        if (rem - i >= 0)
            ans = (ans + rec(rem - i)) % MOD;
    // return
    return dp[rem] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cout << rec(N);
    return 0;
}