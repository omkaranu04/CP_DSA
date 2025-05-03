#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    // col start
    for (ll i = 0; i < n; i++)
    {
        ll mini = a[0][i];
        for (ll k = 0; k + i < n && k < n; k++)
        {
            mini = min(mini, a[k][i + k]);
        }
        // cout << mini << "\n";
        if (mini < 0)
            ans += abs(mini);
        for (ll k = 0; k + i < n && k < n; k++)
        {
            a[k][i + k] += abs(mini);
        }
    }
    // row start
    for (ll i = 1; i < n; i++)
    {
        ll mini = a[i][0];
        for (ll k = 0; k + i < n && k < n; k++)
        {
            mini = min(mini, a[i + k][k]);
        }
        // cout << mini << "\n";
        if (mini < 0)
            ans += abs(mini);
        for (ll k = 0; k + i < n && k < n; k++)
        {
            a[i + k][k] += abs(mini);
        }
    }
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