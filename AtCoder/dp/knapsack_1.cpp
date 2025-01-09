#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> w(110), v(110);
ll N, W;
ll dp[110][100010];
ll knapsack(ll index, ll weight_rem)
{
    // basecase
    if (weight_rem < 0)
        return -1;
    if (index >= N)
        return 0;
    if (dp[index][weight_rem] != -1)
        return dp[index][weight_rem];

    // not take
    ll ans = knapsack(index + 1, weight_rem);

    // take
    if (weight_rem >= w[index])
    {
        ans = max(ans, knapsack(index + 1, weight_rem - w[index]) + v[index]);
    }

    return dp[index][weight_rem] = ans;
}
int main()
{
    cin >> N >> W;
    for (ll i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(0, W) << endl;
}