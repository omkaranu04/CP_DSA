#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<vector<ll>> g;
vector<pair<ll, ll>> edges;
vector<ll> dis;
ll t = 1;
void dfs(ll u)
{
    dis[u] = t++;
    for (auto v : g[u])
    {
        if (dis[v] == 0)
            dfs(v);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll u = 1; u <= n; u++)
        if (dis[u] == 0)
            dfs(u);

    for (auto [u, v] : edges)
    {
        if (dis[u] < dis[v])
            cout << u << " " << v << endl;
        else
            cout << v << " " << u << endl;
    }
    return 0;
}