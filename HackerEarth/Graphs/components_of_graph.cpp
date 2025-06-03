#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, k;
vector<vector<ll>> g, gr;
vector<ll> aqi;
vector<ll> vis, topo;
vector<pair<ll, ll>> edges;
void dfs1(ll node)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
            dfs1(v);
    }
    topo.push_back(node);
}
void dfs2(ll node, ll &sz)
{
    vis[node] = 1;
    sz++;
    for (auto v : gr[node])
    {
        if (!vis[v])
            dfs2(v, sz);
    }
}
bool check(ll mid)
{
    // reset all
    g.clear();
    gr.clear();
    vis.clear();
    topo.clear();

    g.resize(n + 1);
    gr.resize(n + 1);
    for (auto &[u, v] : edges)
    {
        if (aqi[u] >= mid && aqi[v] >= mid)
        {
            g[u].push_back(v);
            gr[v].push_back(u);
        }
    }

    vis.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (aqi[i] >= mid && !vis[i])
            dfs1(i);
    }

    reverse(topo.begin(), topo.end());
    vis.assign(n + 1, 0);

    for (auto i : topo)
    {
        if (aqi[i] < mid || vis[i])
            continue;
        ll sz = 0;
        dfs2(i, sz);
        if (sz >= k)
            return true;
    }

    return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    aqi.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> aqi[i];
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    ll lo = 0, hi = 1e18, ans;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans << endl;
    return 0;
}