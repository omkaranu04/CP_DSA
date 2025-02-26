#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll X = sum - a[i];
        ll lo = lower_bound(a.begin(), a.end(), X - y) - a.begin();
        ll hi = upper_bound(a.begin(), a.end(), X - x) - a.begin();

        if (lo <= i)
            lo = i + 1;
        if (hi <= i)
            continue;

        ans += (hi - lo);
    }
    // cout << "ans : ";
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