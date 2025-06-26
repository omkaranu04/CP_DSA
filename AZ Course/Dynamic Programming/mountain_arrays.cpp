#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;
ll n, k;
vector<ll> a;
vector<vector<ll>> dp;
ll rec(ll l, ll r)
{
    ll idx = min(l, r) - 1;
    if (idx < 0)
        return l != (n - 1) && r != (n - 1);
    if (dp[l][r] != -1)
        return dp[l][r];
    ll ans = 0;
    if (abs(a[idx] - a[l]) <= k)
    {
        ans += rec(idx, r);
        ans %= mod;
    }
    if (abs(a[idx] - a[r]) <= k)
    {
        ans += rec(l, idx);
        ans %= mod;
    }
    return dp[l][r] = ans;
}
void solve()
{
    a.clear();
    dp.clear();

    cin >> n >> k;
    a.resize(n);
    dp.resize(n + 1, vector<ll>(n + 1, -1));
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cout << rec(n - 1, n - 1) << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}