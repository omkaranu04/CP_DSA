#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long
#define endl "\n"
const ll mod = 1e9 + 7;
const ll MAXN = 1e7 + 10;
ll L, R, lim;
vector<ll> isPrime, primes;
vector<ll> rem, cnt;
void sieve()
{
    fill(isPrime.begin(), isPrime.end(), 1LL);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i * i <= lim; i++)
    {
        if (isPrime[i])
        {
            for (ll j = i * i; j <= lim; j += i)
                isPrime[j] = 0;
        }
    }

    primes.clear();
    for (ll i = 2; i <= lim; i++)
        if (isPrime[i])
            primes.push_back(i);

    for (auto p : primes)
    {
        ll st = (L + p) / p * p;
        for (ll i = st; i <= R; i += p)
        {
            ll id = i - L - 1;
            if (rem[id] % p == 0)
            {
                cnt[id]++;
                while (rem[id] % p == 0)
                    rem[id] /= p;
            }
        }
    }
}
void solve()
{
    if (L == R)
    {
        cout << 1 << endl;
        return;
    }
    ll len = R - L;
    cnt.resize(len, 0);
    rem.resize(len);
    for (ll i = 0; i < len; i++)
        rem[i] = L + 1 + i;

    lim = (ll)(sqrtl((long double)R));
    isPrime.resize(lim + 1, 0);
    sieve();

    ll pcnt = 0;
    for (ll i = 0; i < len; i++)
    {
        if (rem[i] > 1)
            cnt[i]++;
        if (cnt[i] == 1)
            pcnt++;
    }
    cout << 1 + pcnt;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> L >> R;
    solve();
    return 0;
}