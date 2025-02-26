#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    x = abs(x);
    y = abs(y);
    ll a = (x + k - 1) / k;
    ll b = (y + k - 1) / k;

    ll ans = max(2 * a - 1, 2 * b);
    cout << ans << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}