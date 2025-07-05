#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 100;
vector<ll> isPrime(MAXN), primes;
void sieve()
{
    isPrime.assign(MAXN, 1);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i * i < MAXN; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j < MAXN; j += i)
                isPrime[j] = 0;
        }
    }
    for (ll i = 0; i < MAXN; i++)
        if (isPrime[i])
            primes.push_back(i);
}
ll GCD(ll a, ll b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll T;
    cin >> T;
    while (T--)
    {
        ll A, B;
        cin >> A >> B;
        ll ans = 0;
        ll gcdAB = GCD(A, B);
        for (auto p : primes)
        {
            if (p > gcdAB)
                break;
            if (gcdAB % p == 0)
                ans++;
            while (gcdAB % p == 0)
                gcdAB /= p;
        }
        if (gcdAB > 1)
            ans++;
        cout << ans + 1 << endl;
    }
    return 0;
}