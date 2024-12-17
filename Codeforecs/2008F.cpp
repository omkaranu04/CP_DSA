#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll binExp(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll res = binExp(a, b / 2, m);
    if (b % 2)
        return (((res * res) % m) * a) % m;
    return (res * res) % m;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        sum %= MOD;
    }
    ll squareSum = 0;
    for (int i = 0; i < n; i++)
    {
        squareSum += (a[i] * a[i]) % MOD;
        squareSum %= MOD;
    }

    ll p = (sum * sum) % MOD;
    p = (p - squareSum + MOD) % MOD;
    ll q = (n * (n - 1)) % MOD;

    if (q == 0)
    {
        cout << 0 << endl;
        return;
    }

    ll q_inv = binExp(q, MOD - 2, MOD);

    ll ans = (p * q_inv) % MOD;
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}