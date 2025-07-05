#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> ps(n + 1, 0);
    ll ans = 1e18, l = 0, sum = 0;
    for (ll r = 0; r < n; r++)
    {
        sum += a[r];
        while (sum > k && l <= r)
        {
            ans = min(ans, sum - k);
            sum -= a[l++];
            if (l <= r)
                ans = min(ans, llabs(sum - k));
        }
        if (l <= r)
            ans = min(ans, llabs(sum - k));
    }
    cout << ans << "\n";
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