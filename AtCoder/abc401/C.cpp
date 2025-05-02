#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1000000000LL;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<ll> dp(N + 1, 0);

    int limit = min(N, K - 1);
    for (int i = 0; i <= limit; i++)
    {
        dp[i] = 1;
    }

    ll window = 0;
    for (int i = 0; i < K && i <= N; i++)
    {
        window = (window + dp[i]) % MOD;
    }

    for (int i = K; i <= N; i++)
    {
        dp[i] = window % MOD;
        if (i + 1 <= N)
        {
            window = (window + dp[i] - dp[i - K] + MOD) % MOD;
        }
    }

    cout << dp[N] % MOD << "\n";
    return 0;
}