#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
const int MAXN = 100010;
vector<ll> fact(MAXN + 1, 1), invfact(MAXN + 1, 1);
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = modpow(a, b / 2);
    res = (res * res) % mod;
    if (b % 2)
        res = (res * a) % mod;
    return res;
}
void fillfact()
{
    for (ll i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    invfact[MAXN] = modpow(fact[MAXN], mod - 2);
    for (ll i = MAXN; i >= 1; i--)
        invfact[i - 1] = (invfact[i] * i) % mod;
}
void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    ll nmod = (k * (a - 1) + 1) % mod;
    ll num = 1;
    for (ll i = 0; i < a; i++)
    {
        ll x = nmod - i;
        if (x < 0)
            x += mod;
        num = (num * x) % mod;
    }
    ll combine = (num * 1LL * invfact[a]) % mod;
    ll mmod = (((b - 1) * k) % mod * combine % mod + 1) % mod;
    cout << nmod << " " << mmod << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    fillfact();
    while (t--)
        solve();
    return 0;
}