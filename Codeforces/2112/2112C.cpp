#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    for (ll k = 2; k < n; k++)
    {
        ll thresh = max(a[n - 1] - a[k], a[k]);
        ll l = 0, r = k - 1;
        while (l < r)
        {
            if (a[l] + a[r] > thresh)
            {
                ans += r - l;
                r--;
            }
            else
                l++;
        }
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