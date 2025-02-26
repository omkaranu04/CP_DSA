#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
void solve()
{
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll x = a + b + c;
    ll ans = 3 * (n / x);
    n = n % x;
    if (n == 0)
        cout << ans << endl;
    else if (n <= a)
        cout << ans + 1 << endl;
    else if (n <= a + b)
        cout << ans + 2 << endl;
    else
        cout << ans + 3 << endl;
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