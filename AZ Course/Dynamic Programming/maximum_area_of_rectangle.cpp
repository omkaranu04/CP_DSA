#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    ll dp[n][m];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            dp[i][j] = 0;
            if (grid[i][j] == 1)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i][j - 1] + 1;

                ll w = dp[i][j]; // fix width

                // search height
                for (ll k = i; k >= 0; k--)
                {
                    w = min(w, dp[k][j]);
                    ans = max(ans, w * (i - k + 1));
                }
            }
        }
    }
    // cout << "ans : ";
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