#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, s;
    cin >> n >> s;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll dx, dy;
        ll x, y;
        cin >> dx >> dy >> x >> y;
        ll a = (dx == 1 ? s - x : x);
        ll b = (dy == 1 ? s - y : y);
        if (a == b)
            ans++;
    }
    cout << ans << endl;
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