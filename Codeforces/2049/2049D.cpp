#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> a;
    a.resize(n + 1, vector<ll>(m + 1));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    // lets maintain dp with shifts
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
    dp[0][0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        vector<ll> x(m, 1e18);
        for (ll sft = 0; sft < m; sft++)
        {
            for (ll j = 0; j < m; j++)
                x[j] = dp[i - 1][j] + a[i][(j + sft) % m] + k * sft;
            for (ll j = 0; j < m; j++)
                x[j] = min(x[j], x[(j - 1 + m) % m] + a[i][(j + sft) % m]);
            for (ll j = 0; j < m; j++)
                dp[i][j] = min(dp[i][j], x[j]);
        }
    }
    cout << dp[n][m - 1] << "\n";
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