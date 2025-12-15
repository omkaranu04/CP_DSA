#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll INF = 4e18;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> pmin(n), ps(n);
    pmin[0] = a[0];
    ps[0] = pmin[0];
    for (ll i = 1; i < n; i++)
    {
        pmin[i] = min(pmin[i - 1], a[i]);
        ps[i] = ps[i - 1] + pmin[i];
    }
    ll ans = ps[n - 1];
    for (ll i = 0; i < n - 1; i++)
    {
        ll pn = (i > 0) ? pmin[i - 1] : INF;
        ll pm = (i > 0) ? ps[i - 1] : 0LL;
        ans = min(ans, pm + min(pn, a[i] + a[i + 1]));
    }
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