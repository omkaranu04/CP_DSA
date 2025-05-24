#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll modexp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = modexp(a, b / 2, mod);
    res = (res * 1LL * res) % mod;
    if (b % 2 == 0)
        return res;
    else
        return (res * 1LL * a) % mod;
}
void solve()
{
    ll a, b, c, p;
    cin >> a >> b >> c >> p;
    if (b == 0 && c != 0)
        cout << "1\n";
    else if (a % p == 0 || a == 0)
        cout << "0\n";
    else
    {
        ll x = modexp(b, c, p - 1);
        x = modexp(a, x, p);
        cout << x << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}