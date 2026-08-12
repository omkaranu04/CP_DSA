#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> b(n);
    for (auto &x : b)
        cin >> x;
    vector<ll> bl(n), br(n);
    for (ll i = 0; i < n; i++)
    {
        bl[i] = b[i] + (i);
        br[i] = b[i] - (i);
    }
    vector<ll> pmax(n), smax(n);
    pmax[0] = bl[0];
    smax[n - 1] = br[n - 1];
    for (ll i = 1; i < n; i++)
        pmax[i] = max(pmax[i - 1], bl[i]);
    for (ll i = n - 2; i >= 0; i--)
        smax[i] = max(smax[i + 1], br[i]);
    ll ans = LLONG_MIN;
    for (ll i = 1; i <= n - 2; i++)
        ans = max(ans, b[i] + pmax[i - 1] + smax[i + 1]);
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