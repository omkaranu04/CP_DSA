#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        ll mx = a[n - 1], mn = a[0];
        ll ans = mx - mn - 1;
        if (ans < 0)
            cout << 0 << "\n";
        else
            cout << ans << "\n";
    }
}