#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll mod = 1e9 + 7, m = 1e6 + 10;
ll dp[m][2];
ll rec(ll i, ll type)
{
    if (i == 1)
        return 1;
    if (dp[i][type] != -1)
        return dp[i][type];
    ll ans = 0;
    if (type == 0)
        ans = (ans % mod + (2 * 1LL * rec(i - 1, 0)) % mod + rec(i - 1, 1) % mod) % mod;
    else
        ans = (ans % mod + (4 * 1LL * rec(i - 1, 1)) % mod + rec(i - 1, 0) % mod) % mod;

    return dp[i][type] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    ll ans = (rec(n, 0) % mod + rec(n, 1) % mod) % mod;
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