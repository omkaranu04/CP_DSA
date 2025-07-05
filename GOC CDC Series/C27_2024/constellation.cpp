#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
ll a[1010], b[1010];
ll dp[1010][1010];
ll rec(ll i, ll j, ll cmin, ll cmax)
{
    if (i == n && j == m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    ll ans = -1e18;
    if (i < n)
    {
        ll nmin = min(cmin, a[i]), nmax = max(cmax, a[i]);
        ans = max(ans, (nmax - nmin) + rec(i + 1, j, nmin, nmax));
    }
    if (j < m)
    {
        ll nmin = min(cmin, b[j]), nmax = max(cmax, b[j]);
        ans = max(ans, (nmax - nmin) + rec(i, j + 1, nmin, nmax));
    }
    return dp[i][j] = ans;
}
void solve()
{
    cin >> n >> m;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 0, 1e18, -1e18) << endl;
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