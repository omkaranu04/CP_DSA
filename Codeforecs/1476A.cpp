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
        ll n, k;
        cin >> n >> k;
        if (n == k)
            cout << 1 << endl;
        else if (n == 1)
            cout << k << endl;
        else
        {
            ll cf = ((n + k - 1) / k);
            ll ans = (cf * k + n - 1) / n;
            cout << ans << endl;
        }
    }
    return 0;
}