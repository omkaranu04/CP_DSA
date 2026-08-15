#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 998244353;
const ll N = 200010;
vector<ll> fact(N), invfact(N);
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = modpow(a, b / 2);
    t = (t * t) % MOD;
    if (b % 2)
        return (t * a) % MOD;
    else
        return t % MOD;
}
ll ncr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    ll ans = (fact[n] * 1LL * invfact[r]) % MOD;
    ans = (ans * 1LL * invfact[n - r]) % MOD;
    return ans % MOD;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    fact[0] = 1;
    for (ll i = 1; i <= n; i++)
        fact[i] = (i * fact[i - 1]) % MOD;
    invfact[n] = modpow(fact[n], MOD - 2);
    for (ll i = n; i >= 1; i--)
        invfact[i - 1] = (invfact[i] * i) % MOD;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll ans1 = 0, ans2 = 0;
    for (auto x : a)
        ans1 = (ans1 + modpow(x, 2)) % MOD;

    ll sum = 0;
    for (auto x : a)
        sum = (sum + x) % MOD;

    ans2 = ((sum * 1LL * sum) % MOD - ans1 + MOD) % MOD;

    ans1 = (ans1 * 1LL * ncr(n - 1, k - 1)) % MOD;
    ans2 = (ans2 * 1LL * ncr(n - 2, k - 2)) % MOD;

    ll ans = (ans1 + ans2) % MOD;
    cout << ans << endl;
    return 0;
}