#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, x, y;
vector<ll> a, b;
ll dp[100100][2];
ll rec(ll i, ll isA)
{
    // base case
    if (i == n)
        return 0;
    if (dp[i][isA] != -1)
        return dp[i][isA];
    ll ans = 1e18;
    if (isA)
    {
        ans = min(ans, a[i] + rec(i + 1, 1));
        ans = min(ans, a[i] + x + rec(i + 1, 0));
    }
    else
    {
        ans = min(ans, b[i] + rec(i + 1, 0));
        ans = min(ans, b[i] + y + rec(i + 1, 1));
    }
    return dp[i][isA] = ans;
}
void solve()
{
    a.clear();
    b.clear();
    memset(dp, -1, sizeof(dp));

    cin >> n;
    a.resize(n);
    b.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    cin >> x >> y;
    ll ans = min(rec(0, 1), rec(0, 0));
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