#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n), d(n);
        ll tota = 0, mina = LLONG_MAX;
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            d[i] = a[i] - b[i];
            tota += a[i];
            mina = min(mina, a[i]);
        }
        sort(d.rbegin(), d.rend());
        ll ps = 0, best = 0;
        for (ll m = 1; m <= n; m++)
        {
            ps += d[m - 1];
            ll khatam = 2 * m - n;
            ll p = (khatam > 0 ? khatam * mina : 0);
            if (ps - p > best)
                best = ps - p;
        }
        cout << tota - best << endl;
    }
    return 0;
}