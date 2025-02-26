#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll rec(ll l, ll r, vector<ll> &v, vector<vector<ll>> &dp)
{
    if (abs(l - r) == 1)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];

    ll ans = 1e18;

    for (int i = l + 1; i <= r - 1; i++)
    {
        ans = min(ans, rec(l, i, v, dp) + rec(i, r, v, dp) + v[l] * v[i] * 1LL * v[r]);
    }

    return dp[l][r] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> v[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
    ll ans = rec(1, n, v, dp);
    cout << ans << "\n";
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