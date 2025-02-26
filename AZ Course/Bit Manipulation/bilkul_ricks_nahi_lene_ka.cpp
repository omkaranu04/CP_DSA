#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    for (ll i = 0; i < 64; i++)
    {
        if ((x & (1LL << i)) && (y & (1LL << i)))
        {
            ans += (1LL << (i + 1));
        }
        else if ((x & (1LL << i)) || (y & (1LL << i)))
        {
            ans += (1LL << i);
        }
    }
    cout << ans << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}