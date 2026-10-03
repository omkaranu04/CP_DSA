#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, L, D;
        cin >> n >> L >> D;
        ll ans = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (D >= x)
                ans += (D - x) / (2 * L) + 1;
            ll t = 2 * L - x;
            if (D >= t)
                ans += (D - t) / (2 * L) + 1;
        }
        cout << ans << endl;
    }
    return 0;
}