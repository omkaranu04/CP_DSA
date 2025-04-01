#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

using namespace std;
#define endl "\n"
#define mod 1000000007

int n, m;
vector<vector<int>> g;
int dp[21][(1 << 20) + 1];
int rec(int node, int mask)
{
    if (mask == ((1 << n) - 1))
    {
        if (node == n)
            return 1;
        return 0;
    }
    if (dp[node][mask] != -1)
        return dp[node][mask];

    int ans = 0;
    for (auto v : g[node])
    {
        if (mask & (1 << (v - 1)))
            continue;
        ans = (ans + rec(v, (mask | (1 << (v - 1))))) % mod;
    }

    return dp[node][mask] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(dp, -1, sizeof(dp));

    cout << rec(1, 1) << endl;
    return 0;
}