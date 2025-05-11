#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 998244353;
const ll MAX = 4000100;
vector<ll> fact(MAX), invfact(MAX);
ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res = (res * res) % mod;
    if (b % 2)
        res = (res * a) % mod;
    return res;
}
void init()
{
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (fact[i - 1] * i) % mod;
    invfact[MAX - 1] = binpow(fact[MAX - 1], mod - 2);
    for (int i = MAX - 2; i >= 1; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}
ll ncr(ll n, ll r)
{
    if (n < r || n < 0 || r < 0)
        return 0;
    ll ans = (fact[n] * invfact[r]) % mod;
    ans = (ans * invfact[n - r]) % mod;
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    init();
    ll a, o, b, g;
    cin >> a >> o >> b >> g;
    ll ans = 0, n = a + o + b + g;
    for (int i = a; i <= min(a + o, n - b - 1); i++)
    {
        ll temp = (ncr(i - 1, a - 1) * ncr(n - i, b)) % mod;
        ans = (ans + temp) % mod;
    }
    cout << ans << endl;
    return 0;
}