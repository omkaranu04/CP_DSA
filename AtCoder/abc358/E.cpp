#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 998244353
ll fact[1005], invfact[1005], dp[1005][26], c[26];
ll binexp(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binexp(a, b / 2);
    res = (res * res) % MOD;
    if (b % 2)
        res = (res * a) % MOD;
    return res;
}
ll rec(ll len, ll idx)
{
    if (len == 0)
        return 1;
    if (idx == 26)
        return 0;
    if (dp[len][idx] != -1)
        return dp[len][idx];
    ll ans = 0;
    for (ll i = 0; i <= min(len, c[idx]); i++)
    {
        ans = (ans % MOD + rec(len - i, idx + 1) * 1LL * invfact[i] % MOD) % MOD;
    }
    return dp[len][idx] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll k;
    cin >> k;
    for (ll i = 0; i < 26; i++)
        cin >> c[i];
    fact[0] = 1;
    for (ll i = 1; i <= 1000; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for (ll i = 0; i <= 1000; i++)
        invfact[i] = binexp(fact[i], MOD - 2);
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (ll len = 1; len <= k; len++)
    {
        ans = (ans % MOD + rec(len, 0) * 1LL * fact[len] % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}