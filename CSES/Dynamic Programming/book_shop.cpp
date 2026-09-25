#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
// const ll MAXN = 1010, MAXX = 100010;
// ll N, X;
// ll dp[MAXN][MAXX];
// vector<pair<ll, ll>> b(MAXN); // (price, page)
// ll rec(ll i, ll rem)
// {
//     // base case
//     if (i > N)
//         return 0;
//     if (rem == 0)
//         return 0;
//     // dp check and return
//     if (dp[i][rem] != -1)
//         return dp[i][rem];
//     // transition
//     ll ans = rec(i + 1, rem);
//     if (rem - b[i].first >= 0)
//         ans = max(ans, b[i].second + rec(i + 1, rem - b[i].first));
//     // return
//     return dp[i][rem] = ans;
// }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // memset(dp, -1, sizeof(dp));
    // cin >> N >> X;
    // for (ll i = 1; i <= N; i++)
    //     cin >> b[i].first;
    // for (ll i = 1; i <= N; i++)
    //     cin >> b[i].second;
    // cout << rec(1, X); // -> rec will fail (TLE)

    ll N, X;
    cin >> N >> X;
    vector<ll> h(N + 1), s(N + 1);
    for (ll i = 1; i <= N; i++)
        cin >> h[i];
    for (ll i = 1; i <= N; i++)
        cin >> s[i];
    vector<ll> dp(X + 1, 0);
    for (ll i = 1; i <= N; i++)
    {
        for (ll rem = X; rem >= h[i]; rem--)
        {
            dp[rem] = max(dp[rem], dp[rem - h[i]] + s[i]);
        }
    }
    cout << dp[X];
    return 0;
}