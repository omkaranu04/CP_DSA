#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
ll n, m;
vector<vector<ll>> g, gr;
vector<ll> topo, vis, ans;
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
void dfs2(ll node, vector<ll> &comp)
{
    vis[node] = 1;
    comp.push_back(node);
    for (auto v : gr[node])
    {
        if (!vis[v])
            dfs2(v, comp);
    }
}
int main()
{
    cin >> n >> m;
    g.resize(n + 1);
    gr.resize(n + 1);
    vis.resize(n + 1, 0);
    ans.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs1(i);
    }
    reverse(topo.begin(), topo.end());
    vis.assign(n + 1, 0);
    for (auto node : topo)
    {
        if (!vis[node])
        {
            vector<ll> tmp;
            dfs2(node, tmp);

            if (tmp.size() > 1)
            {
                for (auto x : tmp)
                    ans[x] = 1;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
}