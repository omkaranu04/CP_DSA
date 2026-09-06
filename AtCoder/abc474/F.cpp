#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll floorDiv(ll a, ll b)
{
    ll q = a / b, r = a % b;
    if (r != 0 && ((r < 0) != (b < 0)))
        q--;
    return q;
}
ll ceilDiv(ll a, ll b)
{
    return -floorDiv(-a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];

    vector<ll> mu(n + 1, 0), primes, comp(n + 1, 0);
    mu[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        if (!comp[i])
        {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (auto p : primes)
        {
            if (i * p > n)
                break;
            comp[i * p] = true;
            if (i % p == 0)
            {
                mu[i * p] = 0;
                break;
            }
            else
            {
                mu[i * p] = -mu[i];
            }
        }
    }

    ll maxA = *max_element(a.begin() + 1, a.end());
    vector<ll> d(n + 1), e(n + 1);
    bool poss = true;
    ll l = maxA, r = LLONG_MAX;
    for (ll j = 1; j <= n; j++)
    {
        d[j] = 0;
        e[j] = 0;
        for (ll k = 1; k * j <= n; k++)
        {
            d[j] += mu[k];
            e[j] += mu[k] * a[k * j];
        }
        if (d[j] > 0)
            l = max(l, ceilDiv(e[j], d[j]));
        else if (d[j] < 0)
            r = min(r, floorDiv(e[j], d[j]));
        else if (e[j] > 0)
            poss = false;
    }
    if (!poss || l > r)
    {
        cout << -1 << endl;
        return 0;
    }
    for (ll j = 1; j <= n; j++)
    {
        ll t = d[j] * l - e[j];
        if (t < 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << l - a[1] << endl;
    return 0;
}