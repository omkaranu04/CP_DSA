#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll N, K;
const ll MAXN = 110, MAXK = 100010;
ll dp[MAXK], a[MAXN];
ll rec(ll rem)
{
    // base case -> he looses if there are no stones left
    if (rem == 0)
        return 0;
    // invalid state
    if (rem < 0)
        return 1e18;
    // dp check and return
    if (dp[rem] != -1)
        return dp[rem];
    // transition
    ll ans = 0;
    for (ll i = 1; i <= N; i++)
    {
        ll x = a[i];
        ll temp = rec(rem - x);
        if (temp == 0)
            ans = 1;
    }
    // return
    return dp[rem] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    for (ll i = 1; i <= N; i++)
        cin >> a[i];

    // Recursion Fails (reason unknown)
    // cout << (rec(K) ? "First" : "Second") << endl;

    memset(dp, 0, sizeof(dp));
    for (ll k = 0; k <= K; k++)
    {
        for (ll i = 1; i <= N; i++)
            if (k - a[i] >= 0 && dp[k - a[i]] == 0)
                dp[k] = 1;
    }
    cout << (dp[K] ? "First" : "Second") << endl;
    return 0;
}