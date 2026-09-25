#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 10010, MAXD = 110;
ll D, N;
string s1, s2;
ll dp[MAXN][MAXD][3][3];
ll rec(ll i, ll rem, ll tl, ll tr)
{
    // base case
    if (i == N)
        return (rem == 0) ? 1 : 0;
    // dp check and return
    if (dp[i][rem][tl][tr] != -1)
        return dp[i][rem][tl][tr];
    // transition
    ll l = 0, r = 9;
    if (tl)
        l = (s1[i] - '0');
    if (tr)
        r = (s2[i] - '0');
    ll ans = 0;
    for (ll d = l; d <= r; d++)
    {
        ll ntl = tl, ntr = tr;
        if (tl == 1 && d > (s1[i] - '0'))
            ntl = 0;
        if (tr == 1 && d < (s2[i] - '0'))
            ntr = 0;
        ans = (ans + rec(i + 1, (rem + d) % D, ntl, ntr)) % MOD;
    }
    // return
    return dp[i][rem][tl][tr] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> s2;
    cin >> D;
    for (ll i = 0; i < s2.length() - 1; i++)
        s1.push_back('0');
    s1 += '1';
    N = s1.length();
    // cout << s1 << "\n" << s2 << endl;
    cout << rec(0, 0, 1, 1);
    return 0;
}