#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    vector<ll> c(n + 1), a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> c[i];
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> dp(n + 1, 1e18);
    dp[1] = c[1];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= min(n, i + a[i]); j++)
        {
            dp[j] = min(dp[j], dp[i] + c[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
