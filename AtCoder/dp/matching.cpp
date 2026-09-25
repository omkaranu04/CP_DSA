#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 22;
ll N;
ll a[MAXN][MAXN], dp[(1LL << MAXN)];
// mask -> the 1s tell the ladies that have been paired
ll rec(ll mask)
{
    // base case
    if (mask == (1LL << N) - 1)
        return 1;
    // dp check and return
    if (dp[mask] != -1)
        return dp[mask];
    // transitions
    // the first 'cntmen' men have been paired, now searching for (cntmen + 1)th ke liye pair
    ll cntmen = 0;
    for (ll i = 0; i < 32; i++)
        if (mask & (1LL << i))
            cntmen++;
    ll ans = 0;
    for (ll w = 1; w <= N; w++)
    {
        if (mask & (1LL << (w - 1)))
            continue;
        if (!a[cntmen + 1][w])
            continue;
        // pair that women with the (cntmen + 1)th man
        ll newMask = mask | (1LL << (w - 1));
        ans = (ans + rec(newMask)) % MOD;
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
    cout << rec(0);
    return 0;
}