#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, x;
vector<ll> ta, tb;
vector<vector<ll>> dp;
ll rec(ll i, ll bus)
{
    if (i == 0)
    {
        if (bus == 0)
            return ta[0];
        if (bus == 1)
            return tb[0] + x;
    }
    if (dp[i][bus] != -1)
        return dp[i][bus];
    ll ans = 1e18;
    if (bus == 0)
    {
        ans = min(ans, ta[i] + rec(i - 1, 0));
        ans = min(ans, ta[i] + rec(i - 1, 1));
    }
    if (bus == 1)
    {
        ans = min(ans, tb[i] + rec(i - 1, 1));
        ans = min(ans, tb[i] + rec(i - 1, 0) + x);
    }

    return dp[i][bus] = ans;
}
void solve()
{
    cin >> n >> x;
    ta.resize(n);
    tb.resize(n);
    dp.resize(n + 1, vector<ll>(2, -1));
    dp.assign(n + 1, vector<ll>(2, -1));

    for (ll i = 0; i < n; i++)
        cin >> ta[i];
    for (ll i = 0; i < n; i++)
        cin >> tb[i];

    for (ll i = 0; i < n; ++i)
        cout << min(rec(i, 0), rec(i, 1)) << ' ';
    cout << endl;
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