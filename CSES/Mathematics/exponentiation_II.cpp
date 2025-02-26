#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll exp(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = exp(a, b / 2, mod);
    if (b & 1)
        return ((res % mod * res % mod) % mod * a % mod) % mod;
    return ((res % mod * res % mod)) % mod;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    while (n--)
    {
        ll mod = 1e9 + 7;
        ll a, b, c;
        cin >> a >> b >> c;
        ll t = exp(b, c, mod - 1);
        cout << exp(a, t, mod) << endl;
    }
    return 0;
}