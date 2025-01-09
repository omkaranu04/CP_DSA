#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
ll exp(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = exp(a, b / 2);
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
        ll a, b;
        cin >> a >> b;
        cout << exp(a, b) << endl;
    }
    return 0;
}