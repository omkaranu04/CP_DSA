#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 100010;
ll K;
ll dp[MAXN], h[MAXN];
ll rec(ll i)
{
    // base case
    if (i == 1)
        return 0;
    // dp check and return
    if (dp[i] != -1)
        return dp[i];
    // transitions
    ll ans = LLONG_MAX;
    for (ll k = 1; k <= K; k++)
        if (i - k >= 1)
            ans = min(ans, rec(i - k) + llabs(h[i] - h[i - k]));
    // return
    return dp[i] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    ll N;
    cin >> N >> K;
    for (ll i = 1; i <= N; i++)
        cin >> h[i];
    cout << rec(N);
    return 0;
}