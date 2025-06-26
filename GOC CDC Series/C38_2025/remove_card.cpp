#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<ll> a;
ll dp[100][100][100];
ll rec(ll l, ll r, ll x)
{
    if (l > r)
        return 0;
    if (dp[l][r][x] != -1)
        return dp[l][r][x];
    while (l < r && a[l] == a[l + 1])
    {
        l++;
        x++;
    }
    ll ans = rec(l + 1, r, 0) + (x + 1) * (x + 1);
    for (ll i = l + 1; i <= r; i++)
    {
        if (a[l] == a[i])
            ans = max(ans, rec(l + 1, i - 1, 0) + rec(i, r, x + 1));
    }
    return dp[l][r][x] = ans;
}
void solve()
{
    a.clear();
    memset(dp, -1, sizeof(dp));

    cin >> n;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cout << rec(0, n - 1, 0) << endl;
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