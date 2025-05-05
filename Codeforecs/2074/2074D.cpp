#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll retval(ll ri, ll x, ll xi)
{
    long double ans = floor(sqrtl(ri * ri - (x - xi) * (x - xi)));
    ll tmp = ans;
    return tmp;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        ll xi = x[i], ri = r[i];
        for (ll xc = xi - ri; xc <= xi + ri; xc++)
        {
            mp[xc] = max(mp[xc], 2 * retval(ri, xc, xi) + 1);
        }
    }
    ll ans = 0;
    for (auto x : mp)
        ans += x.second;
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}