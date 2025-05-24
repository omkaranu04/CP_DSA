#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll binexp(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll tmp = binexp(a, b / 2);
    tmp = (tmp % mod * tmp % mod) % mod;
    if (b % 2 == 0)
        return tmp;
    else
        return (tmp % mod * a % mod) % mod;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll t1 = binexp(3, 3 * n);
    ll t2 = binexp(7, n);
    ll ans = (t1 - t2 + mod) % mod;
    cout << ans << endl;
    return 0;
}