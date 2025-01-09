#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    vector<ll> dp(x + 1, 0);
    dp[0] = 1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 1; j <= x; j++)
        {
            if (j - c[i] >= 0)
                dp[j] = (dp[j] + dp[j - c[i]]) % 1000000007;
        }
    }
    cout << dp[x] << endl;
    return 0;
}