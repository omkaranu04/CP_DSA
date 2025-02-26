#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll maxi = 0;
        for (int i = 0; i <= n - 2; i++)
        {
            maxi = max(maxi, a[i]);
        }
        ll ans = a[n - 1] + maxi;
        cout << ans << endl;
    }
    return 0;
}