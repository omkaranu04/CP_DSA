#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a = 1, b = 1;
    ll idx = 1;
    while (a % k != 0)
    {
        ll temp = b;
        b = (a + b) % k;
        a = temp;
        idx++;
    }
    ll ans = ((idx % mod) * (n % mod)) % mod;
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