#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll l = 1, r = 1e18;
        while (l <= r)
        {
            ll m = l + (r - l) / 2;
            ll sum = m;
            for (int i = 0; i < n - 1; i++)
            {
                sum += min(m, a[i + 1] - a[i]);
            }
            if (sum >= h)
                r = m - 1;
            else
                l = m + 1;
        }
        cout << l << endl;
    }
    return 0;
}