#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n <= 3)
            cout << -1 << "\n";
        else
        {
            ll ans = n + (n - 1) + (n - 2);
            cout << ans << "\n";
        }
    }
}
