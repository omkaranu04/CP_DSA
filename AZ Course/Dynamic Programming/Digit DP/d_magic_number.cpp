#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll m, d, len;
string L, R;
ll dp[2020][2][2][2020];
ll rec(ll level, ll lth, ll rth, ll num)
{
    if (level == len)
        return (num % m == 0);
    if (dp[level][lth][rth][num] != -1)
        return dp[level][lth][rth][num];

    ll ans = 0, l = 0, r = 9;

    // prune the limits for the range
    if (lth)
        l = L[level] - '0';
    if (rth)
        r = R[level] - '0';

    for (ll i = l; i <= r; i++)
    {
        // relax the conditions for the bounds depending on calls
        ll lthn = lth, rthn = rth;
        if (i != l)
            lthn = 0;
        if (i != r)
            rthn = 0;

        if ((level + 1) % 2 == 0 && i == d)
        {
            ans += rec(level + 1, lthn, rthn, (10 * num + i) % m);
            ans %= mod;
        }
        if ((level + 1) % 2 != 0 && i != d)
        {
            ans += rec(level + 1, lthn, rthn, (10 * num + i) % m);
            ans %= mod;
        }
    }
    return dp[level][lth][rth][num] = ans;
}
void solve()
{
    cin >> m >> d;
    cin >> L >> R;
    len = R.size(); // given that L and R are of same size, else we need to append 0s at the beginning of the L

    memset(dp, -1, sizeof(dp));
    ll ans = rec(0, 1, 1, 0);
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}