#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long int
const ll MOD = 1e9 + 7;

int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 100, 0);
    dp[0] = 1;
    for (ll i = 0; i <= n; i++)
    {
        dp[i + 3] = (dp[i] + dp[i + 3]) % MOD;
        dp[i + 5] = (dp[i] + dp[i + 5]) % MOD;
        dp[i + 10] = (dp[i] + dp[i + 10]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}
