#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll L, R, len;
string s1, s2;
string binary(ll n)
{
    string ret = "";
    while (n)
    {
        if (n % 2 == 1)
            ret.push_back('1');
        else
            ret.push_back('0');
        n /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string adjust(string s, ll len)
{
    if (s.length() == len)
        return s;
    ll diff = llabs(len - s.length());
    string ret = "";
    while (diff--)
        ret.push_back('0');
    ret = ret + s;
    return ret;
}
ll dp[65][2][2][2][2];
ll rec(ll level, ll tlo1, ll thi1, ll tlo2, ll thi2)
{
    // base case
    if (level == len)
        return 0;

    // cache check
    if (dp[level][tlo1][thi1][tlo2][thi2] != -1)
        return dp[level][tlo1][thi1][tlo2][thi2];

    // setting hilo for digit 1
    ll lo1 = 0, hi1 = 1;
    if (tlo1 == 1)
        lo1 = s1[level] - '0';
    if (thi1 == 1)
        hi1 = s2[level] - '0';

    // setting hilo for digit 2
    ll lo2 = 0, hi2 = 1;
    if (tlo2 == 1)
        lo2 = s1[level] - '0';
    if (thi2 == 1)
        hi2 = s2[level] - '0';

    ll ans = 0;
    for (ll i = lo1; i <= hi1; i++)
    {
        for (ll j = lo2; j <= hi2; j++)
        {
            // For first number
            ll ntlo1 = tlo1, nthi1 = thi1;
            if (tlo1 == 1 && i > (s1[level] - '0'))
                ntlo1 = 0;
            if (thi1 == 1 && i < (s2[level] - '0'))
                nthi1 = 0;

            // For second number
            ll ntlo2 = tlo2, nthi2 = thi2;
            if (tlo2 == 1 && j > (s1[level] - '0'))
                ntlo2 = 0;
            if (thi2 == 1 && j < (s2[level] - '0'))
                nthi2 = 0;

            ll tmp = ((ll)(i ^ j) << (len - level - 1));
            ans = max(ans, tmp + rec(level + 1, ntlo1, nthi1, ntlo2, nthi2));
        }
    }

    return dp[level][tlo1][thi1][tlo2][thi2] = ans;
}
void solve()
{
    cin >> L >> R;
    s1 = binary(L);
    s2 = binary(R);
    len = max(s1.length(), s2.length());
    s1 = adjust(s1, len);
    s2 = adjust(s2, len);

    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 1, 1) << endl;
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