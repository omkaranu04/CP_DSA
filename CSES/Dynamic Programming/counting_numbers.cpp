#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n;
string s, t;
ll dp[20][2][2][11][2];
ll rec(ll i, ll lo, ll hi, ll p, ll st)
{
    if (i == n)
        return 1;
    if (dp[i][lo][hi][p][st] != -1)
        return dp[i][lo][hi][p][st];
    ll ans = 0;
    ll l = lo ? s[i] - '0' : 0;
    ll r = hi ? t[i] - '0' : 9;
    for (ll d = l; d <= r; d++)
    {
        ll nlo = lo && (d == (s[i] - '0'));
        ll nhi = hi && (d == (t[i] - '0'));
        if (!st && d == 0)
            ans += rec(i + 1, nlo, nhi, 10, 0);
        else
        {
            if (st && d == p)
                continue;
            ans += rec(i + 1, nlo, nhi, d, 1);
        }
    }
    return dp[i][lo][hi][p][st] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = max(s.length(), t.length());
    while (s.length() < n)
        s = '0' + s;
    while (t.length() < n)
        t = '0' + t;
    cout << rec(0, 1, 1, 10, 0);
    return 0;
}