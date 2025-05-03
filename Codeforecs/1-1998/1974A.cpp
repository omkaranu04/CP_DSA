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
        ll x, y;
        cin >> x >> y;
        ll for_2x2 = (y + 1) / 2;
        ll rem_for_1x1 = for_2x2 * 15 - y * 4;
        if (x <= rem_for_1x1)
        {
            cout << for_2x2 << endl;
        }
        else
        {
            x -= rem_for_1x1;
            ll ans = for_2x2;
            while (x > 0)
            {
                ans++;
                x -= 15;
            }
            cout << ans << endl;
        }
    }
    return 0;
}