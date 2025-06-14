#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll D, len;
string K;
string s1, s2;
ll dp[10001][2][2][110];
ll rec(ll level, ll tlo, ll thi, ll num)
{
    if (level == len)
    {
        if (num == 0)
            return 1;
        return 0;
    }
    if (dp[level][tlo][thi][num] != -1)
        return dp[level][tlo][thi][num];

    ll l = 0, r = 9;
    if (tlo == 1)
        l = (s1[level] - '0');
    if (thi == 1)
        r = (s2[level] - '0');

    ll ans = 0;
    for (ll i = l; i <= r; i++)
    {
        ll ntlo = tlo, nthi = thi;
        if (tlo == 1 && i > s1[level] - '0')
            ntlo = 0;
        if (thi == 1 && i < s2[level] - '0')
            nthi = 0;

        ans += rec(level + 1, ntlo, nthi, (num + i) % D);
        ans %= mod;
    }

    return dp[level][tlo][thi][num] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> K;
    cin >> D;
    s1 = "1";
    s2 = K;
    s1 = string(s2.length() - s1.length(), '0') + s1;
    len = s1.length();
    // cout << s1 << " " << s2 << " " << len << endl;

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0) << endl;
    return 0;
}