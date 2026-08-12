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
        ll n, a, b;
        cin >> n >> a >> b;
        if (b <= a)
        {
            cout << n * a << endl;
        }
        else
        {
            ll k = min(b - a, n);
            ll ans = (b + 1) * k - (k * (k + 1)) / 2;
            ans += a * (n - k);
            cout << ans << endl;
        }
    }
    return 0;
}