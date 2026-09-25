#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;

        vector<ll> primes;
        ll y = x;
        for (ll p = 2; p * p <= y; p++)
        {
            if (y % p == 0)
            {
                primes.push_back(p);
                while (y % p == 0)
                    y /= p;
            }
        }
        if (y > 1)
            primes.push_back(y);

        ll ans = 0;
        for (auto p : primes)
        {
            ll s = 0;
            for (auto x : a)
                if (x % p == 0)
                    s += x;
            ans = max(ans, s);
        }
        cout << ans << endl;
    }
    return 0;
}