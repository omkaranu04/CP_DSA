#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll lcm(ll a, ll b)
{
    if (a == 0 || b == 0)
        return 0;
    ll g = __gcd(a, b);
    return (a / g) * b;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> b(n);
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    ll g = b[0];
    for (ll i = 1; i < n; i++)
        g = __gcd(g, b[i]);
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        v[i] = b[i] / g;
    ll ans = 1;
    for (ll i = 0; i < n - 1; i++)
    {
        ll tmp = __gcd(v[i], v[i + 1]);
        if (v[i] / tmp != 1)
            ans = lcm(ans, v[i] / tmp);
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