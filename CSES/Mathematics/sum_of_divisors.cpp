#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll temp1 = n / i;
        ll j = n / temp1;
        // ans += temp1 * (((i + j) * (j - i + 1)) / 2);
        // cout << ans << " ";
        ll sum = ((i + j) % mod) * ((j - i + 1) % mod) % mod;
        sum = (sum * ((mod + 1) / 2)) % mod;
        ans = (ans + temp1 * sum % mod) % mod;
        i = j;
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}