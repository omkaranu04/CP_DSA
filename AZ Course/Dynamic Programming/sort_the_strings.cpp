#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<ll> c;
vector<string> a;
vector<vector<ll>> dp;
ll rec(ll idx, ll rev)
{
    if (idx == n)
        return 0;

    if (dp[idx][rev] != -1)
        return dp[idx][rev];

    ll ans = 1e18;

    string prev = a[idx - 1];
    if (rev)
        reverse(prev.begin(), prev.end());

    string curr_n = a[idx];
    string curr_r = a[idx];
    reverse(curr_r.begin(), curr_r.end());

    if (curr_n >= prev)
        ans = min(ans, rec(idx + 1, 0));

    if (curr_r >= prev)
        ans = min(ans, rec(idx + 1, 1) + c[idx]);

    return dp[idx][rev] = ans;
}
void solve()
{
    dp.clear();

    cin >> n;

    a.resize(n);
    c.resize(n);
    dp.assign(n + 1, vector<ll>(2, -1));

    for (ll i = 0; i < n; i++)
        cin >> c[i];
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 1e18;

    ans = min(ans, rec(1, 0));
    ans = min(ans, rec(1, 1) + c[0]);

    cout << ((ans >= 1e18) ? -1 : ans) << endl;
}
int main()
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