#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m, start;
ll edges[25][25], dp[25][(1 << 20) + 10]; // mask the vertices
ll dfs(ll node, ll mask, ll num)
{
    if (dp[node][mask] != -1)
        return dp[node][mask];
    ll ans = 0;
    if (num > 2 && edges[node][start])
        ans++;
    for (ll i = start; i < n; i++) // start from node always
    {
        if ((mask & (1 << i)))
            continue;
        if (edges[node][i])
            ans += dfs(i, (mask | (1 << i)), num + 1);
    }
    return dp[node][mask] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    memset(edges, 0, sizeof(edges));
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u][v] = 1;
        edges[v][u] = 1;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        start = i;
        memset(dp, -1, sizeof(dp));
        ans += dfs(i, (1 << i), 1);
    }
    cout << (ans >> 1) << endl;
    return 0;
}