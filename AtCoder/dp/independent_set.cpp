#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 100010;
ll dp[MAXN][2];
vector<vector<ll>> g(MAXN);
ll N;
// 0 -> white
// 1 -> black
ll rec(ll u, ll p, ll c)
{
    // base case
    // dp check and return
    if (dp[u][c] != -1)
        return dp[u][c];
    // transitions
    ll ans = 1;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        if (c == 0)
            ans = (ans * 1LL * (rec(v, u, 0) + rec(v, u, 1)) % MOD) % MOD;
        else
            ans = (ans * 1LL * rec(v, u, 0) % MOD) % MOD;
    }
    // return
    return dp[u][c] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (ll i = 1; i <= N - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << (rec(1, 0, 0) + rec(1, 0, 1)) % MOD;
    return 0;
}