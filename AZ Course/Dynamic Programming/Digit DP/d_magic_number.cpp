#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll M, D, len;
string L, R;
ll dp[2020][2][2][2020];
ll rec(ll level, ll ltight, ll rtight, ll currmod)
{
    if (level == len)
    {
        if (currmod == 0)
            return 1;
        return 0;
    }
    if (dp[level][ltight][rtight][currmod] != -1)
        return dp[level][ltight][rtight][currmod];

    ll ans = 0, l = 0, r = 9;
    if (ltight)
        l = L[level] - '0';
    if (rtight)
        r = R[level] - '0';

    for (ll i = l; i <= r; i++)
    {
        ll nltight = ltight, nrtight = rtight;
        if (i != l)
            nltight = 0;
        if (i != r)
            nrtight = 0;

        if ((level + 1) % 2 == 0 && i == D)
        {
            ans += rec(level + 1, nltight, nrtight, (10 * currmod + i) % M);
            ans %= mod;
        }
        if ((level + 1) % 2 != 0 && i != D)
        {
            ans += rec(level + 1, nltight, nrtight, (10 * currmod + i) % M);
            ans %= mod;
        }
    }

    return dp[level][ltight][rtight][currmod] = ans;
}
void solve()
{
    cin >> M >> D;
    cin >> L;
    cin >> R;
    len = L.length();

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0) % mod << endl;
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