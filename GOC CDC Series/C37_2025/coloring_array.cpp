#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, k;
vector<ll> cols;
vector<vector<ll>> cost;
ll dp[105][105][105];

ll rec(ll i, ll lastcol, ll rem)
{
    if (rem < 0)
        return 1e18;
    if (i > n)
    {
        if (rem == 0)
            return 0;
        return 1e18;
    }
    if (dp[i][lastcol][rem] != -1)
        return dp[i][lastcol][rem];
    ll ans = 1e18;
    if (cols[i] != 0)
    {
        if (lastcol == cols[i])
            ans = min(ans, rec(i + 1, cols[i], rem));
        else
            ans = min(ans, rec(i + 1, cols[i], rem - 1));
    }
    else
    {
        for (ll c = 1; c <= m; c++)
        {
            if (c == lastcol)
                ans = min(ans, cost[i][c] + rec(i + 1, c, rem));
            else
                ans = min(ans, cost[i][c] + rec(i + 1, c, rem - 1));
        }
    }
    return dp[i][lastcol][rem] = ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cols.clear();
    cost.clear();
    
    cin >> n >> m >> k;
    cols.resize(n + 1, 0);
    cost.resize(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++)
        cin >> cols[i];
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> cost[i][j];
        }
    }
    ll ans = rec(1, 0, k);
    if (ans == 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
