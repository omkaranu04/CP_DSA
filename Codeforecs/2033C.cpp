#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (ll i = 1; i < n / 2; i++)
    {
        ll j = n - i - 1;
        // if no swap
        ll x1 = int(a[i] == a[i - 1]) + int(a[j] == a[j + 1]);
        // if swap
        ll x2 = int(a[j] == a[i - 1]) + int(a[i] == a[j + 1]);
        if (x2 < x1)
            swap(a[i], a[j]);
    }
    for (ll i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            ans++;
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