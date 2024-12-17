#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    sort(a.begin(), a.end());
    ans -= a[n - 1];
    if (a[n - 1] > ans)
    {
        cout << a[n - 1] - ans << "\n";
    }
    else
    {
        cout << ((ans - a[n - 1]) % 2) << "\n";
    }
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