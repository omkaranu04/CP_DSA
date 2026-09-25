#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll maxn = 1e6 + 10;
ll n;
ll dp[maxn][2];
ll rec(ll i, ll t)
{
    // base case
    if (i == 1)
        return 1;
    // dp check and return
    if (dp[i][t] != -1)
        return dp[i][t];
    // transitions
    ll ans = 0;
    if (t == 0)
        ans = (ans + (2LL * rec(i - 1, 0) + rec(i - 1, 1)) % MOD) % MOD;
    else
        ans = (ans + (rec(i - 1, 0) + 4LL * rec(i - 1, 1)) % MOD) % MOD;
    // return
    return dp[i][t] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        cout << (rec(n, 0) + rec(n, 1)) % MOD << endl;
    }
    return 0;
}