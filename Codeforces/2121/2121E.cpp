#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll INF = 1e18;
void solve()
{
    string L, R;
    cin >> L >> R;
    ll n = L.length();

    ll dp[10][2][2];
    for (int i = 0; i <= n; ++i)
        for (int a = 0; a < 2; ++a)
            for (int b = 0; b < 2; ++b)
                dp[i][a][b] = INF;

    dp[0][1][1] = 0;
    for (ll pos = 0; pos < n; pos++)
    {
        for (ll tL = 0; tL <= 1; tL++)
        {
            for (ll tR = 0; tR <= 1; tR++)
            {
                if (dp[pos][tL][tR] < INF)
                {
                    int low = tL ? (L[pos] - '0') : 0;
                    int high = tR ? (R[pos] - '0') : 9;

                    for (ll d = low; d <= high; d++)
                    {
                        int ntL = tL && (d == low);
                        int ntR = tR && (d == high);
                        ll tmp = (d == (L[pos] - '0')) + (d == (R[pos] - '0'));
                        dp[pos + 1][ntL][ntR] = min(dp[pos + 1][ntL][ntR], dp[pos][tL][tR] + tmp);
                    }
                }
            }
        }
    }

    ll ans = INF;
    for (int tL = 0; tL <= 1; ++tL)
        for (int tR = 0; tR <= 1; ++tR)
            ans = min(ans, dp[n][tL][tR]);

    cout << ans << endl;
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