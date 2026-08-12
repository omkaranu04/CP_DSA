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
        ll ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > ans && (i + 1) % 2 == 1)
                ans = a[i];
        }
        cout << ans << endl;
    }
    return 0;
}