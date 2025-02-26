#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll MOD = 1e9 + 7;
ll bin_exp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = bin_exp(a, b / 2, mod);
    if (b % 2)
        return (((res * res) % mod) * a) % mod;
    return (res * res) % mod;
}
ll sumGP(ll a, ll r, ll n)
{
    // i want to calculate a(1-r^n)/(1-r)
    ll num = (1 - bin_exp(r, n, MOD) + MOD) % MOD;
    ll den = (1 - r + MOD) % MOD;
    return (a * num % MOD) * bin_exp(den, MOD - 2, MOD) % MOD;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> factor(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> factor[i].first >> factor[i].second;
    }
    ll num_div = 1, sum_div = 1;
    ll prod_div = 1, temp = 1;
    for (ll i = 0; i < n; i++)
    {
        ll p = factor[i].first, e = factor[i].second;
        sum_div = (sum_div * sumGP(1, p, e + 1)) % MOD;
        num_div = (num_div * (e + 1)) % MOD;

        ll x = bin_exp(p, (e * (e + 1)) / 2, MOD);
        prod_div = bin_exp(prod_div, e + 1, MOD) * bin_exp(x, temp, MOD) % MOD;
        temp = (temp * (e + 1)) % (MOD - 1);
    }
    cout << num_div << " " << sum_div << " " << prod_div << endl;
    return 0;
}