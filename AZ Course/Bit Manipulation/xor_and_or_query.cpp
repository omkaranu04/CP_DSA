#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, q;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(31, 0));
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int a = arr[i - 1];
        int cnt = 0;
        while (a > 0)
        {
            dp[i][cnt] = a % 2;
            a /= 2;
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 31; j++)
            dp[i][j] += dp[i - 1][j];
    }
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        double ans = (r - l + 1.0) / 2.0;
        ll x1 = 0, x2 = 0, x3 = 0;
        for (ll i = 0; i < 31; i++)
        {
            ll p = dp[r][i] - dp[l - 1][i];
            if (p < ans)
                x1 += (1LL << i);
            if (p != (r - l + 1))
                x2 += (1LL << i);
            if (p > 0)
                x3 += (1LL << i);
        }
        ll ans_final = x1 + x2 + x3;
        cout << ans_final << "\n";
    }
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