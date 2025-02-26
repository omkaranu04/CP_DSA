#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 2e6 + 10
vector<bool> sieve(MAX + 1, true);
vector<ll> primes;
ll binexp(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void gen()
{
    sieve[0] = sieve[1] = false;
    for (ll i = 2; i <= MAX; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= MAX; j += i)
                sieve[j] = false;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    gen();
    ll ans = 0;
    for (ll p : primes)
    {
        if (binexp(p, 8) <= n)
            ans++;
        else
            break;
    }
    for (ll i = 0; i < primes.size(); i++)
    {
        for (ll j = i + 1; j < primes.size(); j++)
        {
            __int128 p2p2 = (__int128)primes[i] * primes[i] * primes[j] * primes[j];
            if (p2p2 <= n)
                ans++;
            else
                break;
        }
    }
    cout << ans << endl;
    return 0;
}