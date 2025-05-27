#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll n;
vector<ll> a;
ll dp[510][510];
ll rec(ll l, ll r)
{
    if (l == r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    ll ans = 1e18, tot = 0, sum = 0;
    for (ll i = l; i <= r; i++)
        tot += a[i];
    for (ll mid = l; mid <= r - 1; mid++)
    {
        sum += a[mid];
        ans = min(ans, rec(l, mid) + rec(mid + 1, r) + (sum + (tot - sum)));
    }
    return dp[l][r] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = rec(0, n - 1);
    cout << ans;
    return 0;
}