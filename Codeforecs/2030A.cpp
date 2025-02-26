#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    reverse(a.begin() + 1, a.end());
    b[0] = a[0];
    c[0] = a[0];
    for (ll i = 1; i < n; i++)
    {
        b[i] = min(b[i - 1], a[i]);
        c[i] = max(c[i - 1], a[i]);
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << c[i] << " ";
    // }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += c[i] - b[i];
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