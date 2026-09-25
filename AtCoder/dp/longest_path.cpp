#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 100010;
ll N, M;
vector<vector<ll>> g(MAXN);
ll dp[MAXN];
ll rec(ll u)
{
    // base case
    // dp check and return
    if (dp[u] != -1)
        return dp[u];
    // transitions
    ll ans = 0;
    for (auto v : g[u])
        ans = max(ans, 1 + rec(v));
    // return
    return dp[u] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N >> M;
    for (ll i = 1; i <= M; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    ll ans = 0;
    for (ll i = 1; i <= N; i++)
        ans = max(ans, rec(i));
    cout << ans;
    return 0;
}