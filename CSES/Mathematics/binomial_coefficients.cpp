#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 1e9 + 7;
vector<ll> fact(1000010);
ll bin_exp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = bin_exp(a, b / 2, mod);
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
    for (ll i = 1; i < 1000010; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        ll num = fact[a];
        ll den = (fact[b] % MOD * fact[a - b] % MOD) % MOD;
        ll ans = (num % MOD * bin_exp(den, MOD - 2, MOD) % MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}