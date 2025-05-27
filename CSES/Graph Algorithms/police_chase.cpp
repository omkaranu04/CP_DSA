#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
ll g[501][501], gg[501][501]; // backup graph
ll vis[501], par[501];
ll bfs()
{
    memset(vis, 0, sizeof(vis));
    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (ll v = 1; v <= n; v++)
        {
            if (g[u][v] && !vis[v])
            {
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return vis[n];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(g, 0, sizeof(g));
    memset(gg, 0, sizeof(gg));
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a][b]++, g[b][a]++;
        gg[a][b]++, gg[b][a]++;
    }
    while (bfs())
    {
        ll f = 1e18;
        for (ll v = n; v != 1; v = par[v])
        {
            ll u = par[v];
            f = min(f, g[u][v]);
        }
        for (ll v = n; v != 1; v = par[v])
        {
            ll u = par[v];
            g[u][v] -= f;
            g[v][u] += f;
        }
    }
    bool tmp = bfs();
    vector<pair<ll, ll>> ans;
    for (ll u = 1; u <= n; u++)
    {
        for (ll v = 1; v <= n; v++)
        {
            if (vis[u] && !vis[v] && gg[u][v])
                ans.push_back({u, v});
        }
    }
    cout << ans.size() << endl;
    for (auto &[u, v] : ans)
    {
        cout << u << " " << v << endl;
    }
    return 0;
}