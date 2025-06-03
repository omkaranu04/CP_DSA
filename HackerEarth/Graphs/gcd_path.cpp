#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<vector<ll>> g, gr, dag;
vector<ll> vis, topo, cost, compgcd, comp, topo2, vis2;
vector<set<ll>> dp;
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
void dfs2(ll node, ll compid)
{
    vis[node] = 1;
    comp[node] = compid;
    compgcd[compid] = __gcd(compgcd[compid], cost[node]);
    for (auto v : gr[node])
    {
        if (!vis[v])
            dfs2(v, compid);
    }
}
void dfs3(ll node)
{
    vis2[node] = 1;
    for (auto v : dag[node])
    {
        if (!vis2[v])
            dfs3(v);
    }
    topo2.push_back(node);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    gr.resize(n + 1);
    cost.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> cost[i];
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // Find the SCCs and their sizes, also each node belongs to which SCC
    vis.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i);
    }
    reverse(topo.begin(), topo.end());
    vis.assign(n + 1, 0);
    comp.resize(n + 1, -1);
    compgcd.resize(n + 1, 0LL);
    ll compid = 0;
    for (auto u : topo)
    {
        if (!vis[u])
        {
            ++compid;
            dfs2(u, compid);
        }
    }

    // Build a DAG using the SCCs
    dag.resize(compid + 1);
    vis2.resize(compid + 1, 0);
    for (ll u = 1; u <= n; u++)
    {
        for (auto v : g[u])
        {
            ll cu = comp[u], cv = comp[v];
            if (cu != cv)
                dag[cu].push_back(cv);
        }
    }
    for (auto &x : dag)
    {
        sort(x.begin(), x.end());
        x.erase(unique(x.begin(), x.end()), x.end());
    }
    // Topological sort of the DAG formed
    for (ll i = 1; i <= compid; i++)
    {
        if (!vis2[i])
        {
            dfs3(i);
        }
    }

    reverse(topo2.begin(), topo2.end());

    ll ans = 1e18;
    dp.resize(compid + 1);
    for (auto u : topo2)
    {
        dp[u].insert(compgcd[u]);
        ans = min(ans, compgcd[u]);

        for (auto g0 : dp[u])
        {
            for (auto v : dag[u])
            {
                ll g1 = gcd(g0, compgcd[v]);
                if (!dp[v].count(g1))
                {
                    dp[v].insert(g1);
                    ans = min(ans, g1);
                }
            }
        }
    }
    cout << ans;
    return 0;
}