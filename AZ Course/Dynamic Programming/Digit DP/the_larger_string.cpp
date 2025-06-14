#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
string p;
ll dp[100100][2][2];
// ltight -> 1 tells that same as from prefix side
// rtight -> 1 tells that small or same from suffix side
ll rec(ll i, ll ltight, ll rtight)
{
    if (i == p.length())
    {
        if (ltight == 0 && rtight == 0) // larger from both side, so accept this string
            return 1;
        return 0;
    }
    if (dp[i][ltight][rtight] != -1)
        return dp[i][ltight][rtight];
    ll ans = 0;
    for (ll ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ltight == 1 && ch < p[i]) // we do not want small things
            continue;

        ll nltight = ltight;
        if (ltight == 1 && ch > p[i])
            nltight = 0;

        ll nrtight;
        ll j = i;
        if (ch == p[j]) // if coming from prev state, and maintaining the same char, keep it on
            nrtight = rtight;
        else if (ch > p[j]) // it taking something larger
            nrtight = 0;
        else // else smaller
            nrtight = 1;

        ans += rec(i + 1, nltight, nrtight);
        ans %= mod;
    }

    return dp[i][ltight][rtight] = ans;
}
void solve()
{
    cin >> p;
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1) % mod << endl;
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