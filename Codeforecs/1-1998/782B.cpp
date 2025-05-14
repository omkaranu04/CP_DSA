#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
bool check(ld mid, vector<ll> &x, vector<ll> &v)
{
    ld L = -1e18, R = 1e18;
    for (ll i = 0; i < x.size(); i++)
    {
        ld l = (ld)x[i] - (ld)v[i] * mid;
        ld r = (ld)x[i] + (ld)v[i] * mid;
        L = max(L, l);
        R = min(R, r);
    }
    return L <= R;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> x(n), v(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ld lo = 0.0, hi = 1e12, ans = 0.0;
    while (abs(lo - hi) > 1e-9)
    {
        ld mid = (lo + hi) / 2.0;
        if (check(mid, x, v))
        {
            ans = mid;
            hi = mid;
        }
        else
            lo = mid;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}