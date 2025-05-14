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
        ll ans = 1e9;
        for (ll i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            if (a >= 7)
                ans = min(ans, b);
        }
        if (ans == 1e9)
            cout << "-1\n";
        else
            cout << ans << endl;
    }
}