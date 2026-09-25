#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 100010;
ll dp[MAXN], h[MAXN];
ll rec(ll i)
{
    // base case
    if (i == 1)
        return 0;
    // check dp and return
    if (dp[i] != -1)
        return dp[i];
    // transition
    ll ans = LLONG_MAX;
    if (i - 1 >= 1)
        ans = min(ans, rec(i - 1) + llabs(h[i] - h[i - 1]));
    if (i - 2 >= 1)
        ans = min(ans, rec(i - 2) + llabs(h[i] - h[i - 2]));
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
    cin >> N;
    for (ll i = 1; i <= N; i++)
        cin >> h[i];
    cout << rec(N);
    return 0;
}