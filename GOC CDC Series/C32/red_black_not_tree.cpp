#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
const ll MOD = 1e9 + 7;
void solve()
{
    ll R, r, B, b;
    cin >> R >> r >> B >> b;
    // 1 -> blue, 2 -> red
    ll dp1[R + 1][B + 1][r + 1], dp2[R + 1][B + 1][b + 1];
    memset(dp1, 0, sizeof(dp1));
    memset(dp2, 0, sizeof(dp2));
    dp1[1][0][1] = 1;
    dp2[0][1][1] = 1;
    for (ll i = 0; i <= R; i++)
    {
        for (ll j = 0; j <= B; j++)
        {
            if (i)
            {
                for (ll run = 2; run <= r; run++)
                    dp1[i][j][run] = (dp1[i][j][run] + dp1[i - 1][j][run - 1]) % MOD;

                ll b_end = 0;
                for (ll run = 1; run <= b; run++)
                    b_end = (b_end + dp2[i - 1][j][run]) % MOD;
                dp1[i][j][1] = (dp1[i][j][1] + b_end) % MOD;
            }

            if (j)
            {
                for (ll run = 2; run <= b; run++)
                    dp2[i][j][run] = (dp2[i][j][run] + dp2[i][j - 1][run - 1]) % MOD;

                ll r_end = 0;
                for (ll run = 1; run <= r; run++)
                    r_end = (r_end + dp1[i][j - 1][run]) % MOD;
                dp2[i][j][1] = (dp2[i][j][1] + r_end) % MOD;
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= r; i++)
    {
        ans += dp1[R][B][i];
        ans %= MOD;
    }
    for (ll i = 1; i <= b; i++)
    {
        ans += dp2[R][B][i];
        ans %= MOD;
    }
    cout << ans << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}