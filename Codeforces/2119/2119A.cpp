#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    if (a == b)
    {
        cout << 0 << endl;
        return;
    }
    if (a < b)
    {
        ll diff = b - a;
        ll even = 0, odd = 0;
        if (a % 2 == 0)
        {
            even = (diff + 1) / 2;
            odd = diff / 2;
        }
        else
        {
            even = diff / 2;
            odd = (diff + 1) / 2;
        }
        ll ans = even * min(x, y) + odd * x;
        cout << ans << endl;
    }
    else
    {
        if (a % 2 == 1 && b == a - 1)
            cout << y << endl;
        else
            cout << -1 << endl;
    }
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