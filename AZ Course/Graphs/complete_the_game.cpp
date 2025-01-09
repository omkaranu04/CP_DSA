#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
ll n, m;
vector<vector<ll>> g, revg;
vector<ll> topo, visited, indeg, dp;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    revg.resize(n + 1);
    visited.resize(n + 1, 0);
    indeg.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        revg[b].push_back(a);
        indeg[b]++;
    }
    // Using Kahn's Algorithm
    dp[1] = 1;
    queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        ll top = q.front();
        q.pop();

        for (auto v : g[top])
        {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
        for (auto v : revg[top])
        {
            dp[top] = (dp[top] + dp[v]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}