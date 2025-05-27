#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 1e9 + 7;
vector<ll> fact(1000010), invfact(1000010);
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
    invfact[1000009] = bin_exp(fact[1000009], MOD - 2, MOD);
    for (ll i = 1000009; i >= 1; i--)
    {
        invfact[i - 1] = (invfact[i] * i) % MOD;
    }
    ll n;
    cin >> n;
    while (n--)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = fact[a];
        ans = (ans * invfact[b]) % MOD;
        ans = (ans * invfact[a - b]) % MOD;
        cout << ans << endl;
    }
    return 0;
}