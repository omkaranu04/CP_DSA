#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[5005][5005][3];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, X;
    cin >> N >> X;
    vector<pair<ll, ll>> vits[3];
    for (ll i = 0; i < N; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        vits[a - 1].push_back({b, c});
    }
    ll N0 = vits[0].size(), N1 = vits[1].size(), N2 = vits[2].size();
    memset(dp, 0, sizeof(dp));
    // First vitamin group DP
    for (ll i = 1; i <= N0; i++)
    {
        for (ll j = 1; j <= X; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0];
            if (j - vits[0][i - 1].second >= 0)
            {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - vits[0][i - 1].second][0] + vits[0][i - 1].first);
            }
        }
    }

    // Second vitamin group DP
    for (ll i = 1; i <= N1; i++)
    {
        for (ll j = 1; j <= X; j++)
        {
            dp[i][j][1] = dp[i - 1][j][1];
            if (j - vits[1][i - 1].second >= 0)
            {
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - vits[1][i - 1].second][1] + vits[1][i - 1].first);
            }
        }
    }

    // Third vitamin group DP
    for (ll i = 1; i <= N2; i++)
    {
        for (ll j = 1; j <= X; j++)
        {
            dp[i][j][2] = dp[i - 1][j][2];
            if (j - vits[2][i - 1].second >= 0)
            {
                dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - vits[2][i - 1].second][2] + vits[2][i - 1].first);
            }
        }
    }

    ll ans = 0;
    for (ll c0 = 0; c0 <= X; c0++)
    {
        for (ll c1 = 0; c1 + c0 <= X; c1++)
        {
            ll c2 = X - c0 - c1;
            ans = max(ans, min({dp[N0][c0][0], dp[N1][c1][1], dp[N2][c2][2]}));
        }
    }

    cout << ans << endl;
    return 0;
}