#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 998244353;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> prev_dp = {0, 1};
    for (ll i = 1; i <= n; i++)
    {
        ll m = 2 * i + 1;
        vector<ll> curr_dp(m + 1, 0);
        for (ll k = 1; k <= m; k++)
        {
            ll ways = 0;
            if (k > 1 && k < m)
            {
                ways += prev_dp[k - 1];
                ways %= mod;
            }
            ll l = k - 2, r = m - k - 1;
            if (l >= 2)
            {
                ll c2 = (l * (l - 1) / 2) % mod;
                ways += c2 * prev_dp[k - 2];
                ways %= mod;
            }
            if (l >= 1 && r >= 1)
            {
                ll c2 = (l * r) % mod;
                ways += c2 * prev_dp[k - 1];
                ways %= mod;
            }
            if (r >= 2)
            {
                ll c2 = (r * (r - 1) / 2) % mod;
                ways += c2 * prev_dp[k];
                ways %= mod;
            }
            curr_dp[k] = ways;
        }
        prev_dp = curr_dp;
    }
    for (ll k = 1; k <= 2 * n + 1; k++)
        cout << prev_dp[k] << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}