#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll x, y;
    cin >> x >> y;
    if (x >= y)
    {
        // below and on the diagonal
        ll ans = 0;
        if (x % 2)
            ans += (x - 1) * (x - 1) + 1;
        else
            ans += x * x;

        if (x % 2)
            ans += (y - 1);
        else
            ans -= (y - 1);

        cout << ans << endl;
    }
    else
    {
        // above the diagonal
        ll ans = 0;
        if (y % 2)
            ans += y * y;
        else
            ans += (y - 1) * (y - 1) + 1;

        if (y % 2)
            ans -= (x - 1);
        else
            ans += (x - 1);

        cout << ans << endl;
    }
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}