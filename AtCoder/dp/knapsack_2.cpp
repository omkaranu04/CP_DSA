#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, W;
vector<ll> wts(101), val(101);
vector<vector<ll>> dp;
ll rec(ll i, ll p)
{
    if (p == 0)
        return 0;
    if (i == N)
        return 1e18;
    if (dp[i][p] != -1)
        return dp[i][p];
    ll ans = rec(i + 1, p);
    if (p >= val[i])
    {
        ll take = rec(i + 1, p - val[i]);
        if (take != 1e18)
            ans = min(ans, wts[i] + take);
    }
    return dp[i][p] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> W;
    for (ll i = 0; i < N; i++)
        cin >> wts[i] >> val[i];
    ll maxP = accumulate(val.begin(), val.end(), 0LL);
    dp.resize(N + 1, vector<ll>(maxP + 1, -1));
    ll ans = 0;
    for (ll p = 0; p <= maxP; p++)
        if (rec(0, p) <= W)
            ans = p;
    cout << ans;
    return 0;
}