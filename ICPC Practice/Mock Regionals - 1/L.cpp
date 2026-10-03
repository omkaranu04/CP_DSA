#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 2; i <= n; i++)
        cin >> a[i];
    vector<vector<ll>> dp1(n + 2, vector<ll>(n + 2, 0));
    vector<vector<ll>> dp2(n + 2, vector<ll>(n + 2, 0));
    for (ll i = n; i >= 1; i--)
    {
        for (ll j = i; j >= 1; j--)
        {
            if (a[i] >= a[j] + i - j)
                dp1[i][j] = min(dp1[i + 1][i], dp1[i + 1][j] + abs(a[i] - a[j] - i + j));
            else
                dp1[i][j] = dp1[i + 1][j] + abs(a[i] - a[j] - i + j);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
        {
            if (a[i] <= a[j] - j + i)
                dp2[i][j] = min(dp2[i - 1][i], dp2[i - 1][j] + abs(a[i] - a[j] + j - i));
            else
                dp2[i][j] = dp2[i - 1][j] + abs(a[i] - a[j] + j - i);
        }
    }
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= n; j++)
    //         cout << dp1[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    // for (ll i = 1; i <= n; i++)
    // {
    //     for (ll j = 1; j <= n; j++)
    //         cout << dp2[i][j] << " ";
    //     cout << endl;
    // }

    ll ans = LLONG_MAX;
    for (ll i = 1; i <= n; i++)
        ans = min(ans, dp1[i + 1][i] + dp2[i - 1][i]);
    cout << ans << endl;
    return 0;
}