#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 2), time(n + 2, 1);
    a[0] = 1e9 + 7;
    a[n + 1] = 1e9 + 7;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] > a[i - 1])
        {
            time[i] = 1 + time[i - 1];
        }
    }
    for (ll i = n; i >= 1; i--)
    {
        if (a[i] > a[i + 1])
        {
            time[i] = max(time[i], 1 + time[i + 1]);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ans += time[i];
    }
    cout << ans << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}