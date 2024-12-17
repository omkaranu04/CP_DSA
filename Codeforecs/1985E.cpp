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
        ll x, y, z, k;
        cin >> x >> y >> z >> k;
        ll ans = 0;
        for (ll a = 1; a <= x; a++)
        {
            for (ll b = 1; b <= y; b++)
            {
                if (k % (a * b))
                    continue;
                ll c = k / (a * b);
                if (c > z)
                    continue;
                ll oops = 1ll * (x - a + 1) * (y - b + 1) * (z - c + 1);
                ans = max(ans, oops);
            }
        }
        cout << ans << endl;
    }
    return 0;
}