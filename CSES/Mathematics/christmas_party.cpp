#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll const MOD = 1e9 + 7;
vector<ll> fact(2000010);
ll binexp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = binexp(a, b / 2, mod);
    if (b % 2)
        return (((res * res) % mod) * a) % mod;
    return (res * res) % mod;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    for (ll i = 1; i < 2000010; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll n;
    cin >> n;
    ll ans = fact[n], mul = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll num = fact[n];
        ll den = fact[i];
        ll frac = (num % MOD * binexp(den, MOD - 2, MOD) % MOD) % MOD;
        ans = (ans + (mul * frac) % MOD + MOD) % MOD;
        mul *= -1;
    }
    cout << (ans + MOD) % MOD << endl;
    return 0;
}