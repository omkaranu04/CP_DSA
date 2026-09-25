#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 18;
ll N;
ll dp[(1LL << MAXN)], a[MAXN][MAXN], cost[(1LL << MAXN)];
ll rec(ll mask)
{
    // base case
    if (mask == 0)
        return 0;
    // dp check and return
    if (dp[mask] != -1)
        return dp[mask];
    // transitions
    // find first rabbit in mask
    ll first = -1;
    for (ll i = N; i >= 1; i--)
        if (mask & (1LL << (i - 1)))
            first = i;
    ll ans = LLONG_MIN;
    // try every possible group containing first
    for (ll sub = mask; sub > 0; sub = (sub - 1) & mask)
    {
        if ((sub & (1LL << (first - 1))) == 0)
            continue;
        ans = max(ans, rec(mask ^ sub) + cost[sub]);
    }
    // return
    return dp[mask] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (ll i = 1; i <= N; i++)
        for (ll j = 1; j <= N; j++)
            cin >> a[i][j];

    memset(cost, 0, sizeof(cost));
    for (ll mask = 1; mask < (1LL << N); mask++)
    {
        // find first rabbit in mask
        ll first = -1;
        for (ll i = N; i >= 1; i--)
            if (mask & (1LL << (i - 1)))
                first = i;

        // remove the first rabbit
        ll rem = mask ^ (1LL << (first - 1));
        cost[mask] += cost[rem];
        // check combination with first rabbit
        for (ll j = N; j >= 1; j--)
            if (rem & (1LL << (j - 1)))
                cost[mask] += a[first][j];
    }

    cout << rec((1LL << N) - 1);
    return 0;
}