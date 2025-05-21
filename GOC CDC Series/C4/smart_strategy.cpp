#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll evencnt = 0;
    for (ll i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            evencnt++;
    ll ans = 0;
    for (ll i = 0; i < evencnt; i++)
        if (a[i] % 2 == 1)
            ans++;
    cout << ans << endl;
    return 0;
}
