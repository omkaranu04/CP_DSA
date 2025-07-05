#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 998244353;
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = modpow(a, b / 2);
    res = (res * 1LL * res) % MOD;
    if (b % 2)
        res = (res * 1LL * a) % MOD;
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll maxa = *max_element(a.begin(), a.end()), tot = 0;
    vector<ll> freq(maxa + 10, 0);
    for (auto x : a)
    {
        freq[x]++;
        tot += x;
        if (tot >= MOD)
            tot -= MOD;
    }

    vector<ll> F(maxa + 10, 0);
    for (ll i = maxa - 1; i >= 0; i--)
        F[i] = (F[i + 1] + (freq[i + 1] * 1LL * (i + 1)) % MOD) % MOD;

    vector<ll> H(maxa + 10, 0), dp(maxa + 10, 0);
    for (ll i = maxa; i >= 0; i--)
    {
        ll den = (i + F[i + 1]) % MOD;
        ll rhs = (tot + H[i + 1]) % MOD;

        dp[i] = rhs * modpow(den, MOD - 2) % MOD;
        H[i] = (H[i + 1] + ((freq[i + 1] * 1LL * (i + 1)) % MOD * 1LL * dp[i]) % MOD) % MOD;
    }
    cout << dp[a[c - 1]];
    return 0;
}