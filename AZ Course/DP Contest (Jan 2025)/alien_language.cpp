#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 200200;
const ll ALPHA = 5;
ll dp[MAXN + 1][ALPHA];
// dp[len][last] -> words of length len ending with char last
vector<ll> pred[ALPHA] = {
    {2, 3, 4},
    {0, 2, 3},
    {1, 3},
    {1, 3},
    {2, 3}};
ll rec(ll len, ll last)
{
    if (len == 1)
        return 1;
    if (dp[len][last] != -1)
        return dp[len][last];
    ll ans = 0;
    for (auto p : pred[last])
    {
        ans += rec(len - 1, p);
        if (ans >= MOD)
            ans -= MOD;
    }
    return dp[len][last] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll c = 0; c < ALPHA; c++)
    {
        ans += rec(n, c);
        if (ans >= MOD)
            ans -= MOD;
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        solve();
    }
    return 0;
}