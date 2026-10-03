#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
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
        vector<ll> a(n);
        for (auto &x : a)
            cin >> x;
        ll v = a[n - 1], g = 0;
        ll hi = 0, lo = 0;
        vector<pair<ll, ll>> ch;
        for (ll i = n - 1; i >= 0; i--)
        {
            if (i < n - 1)
            {
                ll d = a[i] - v;
                if (g == 0)
                {
                    hi = max(hi, d);
                    lo = min(lo, d);
                }
                else
                {
                    ll r = ((d % g) + g) % g;
                    if (r)
                        ch.push_back({r, r - g});
                }
            }
            g = __gcd(g, llabs(a[i]));
        }

        sort(ch.begin(), ch.end());
        ll m = ch.size(), t;
        if (m)
            t = ch[m - 1].first;
        else
            t = 0;
        ll ans = max(hi, t) - lo;
        for (ll i = m - 1; i >= 0; i--)
        {
            lo = min(lo, ch[i].second);
            ll t2;
            if (i)
                t2 = ch[i - 1].first;
            else
                t2 = 0;
            ll nhi = max(hi, t2);
            ans = min(ans, nhi - lo);
        }
        cout << ans << endl;
    }
    return 0;
}