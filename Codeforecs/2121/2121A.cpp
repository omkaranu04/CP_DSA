#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    ll L = x[0], R = x[n - 1];
    ll ans;
    if (s <= L)
        ans = R - s;
    else if (s >= R)
        ans = s - L;
    else
    {
        ll lf = 2LL * (s - L) + (R - s);
        ll rf = 2LL * (R - s) + (s - L);
        ans = min(lf, rf);
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