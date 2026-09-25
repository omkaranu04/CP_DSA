#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, X;
    cin >> N >> X;
    ll c[N + 1];
    for (ll i = 1; i <= N; i++)
        cin >> c[i];
    vector<ll> dp(X + 10, 0);
    dp[0] = 1;
    for (ll i = 1; i <= N; i++)
    {
        for (ll x = 1; x <= X; x++)
        {
            if (x - c[i] >= 0)
                dp[x] = (dp[x] + dp[x - c[i]]) % MOD;
        }
    }
    cout << dp[X];
    return 0;
}