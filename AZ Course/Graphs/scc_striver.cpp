// find the strongly connected components in a graph
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> g, g_rev;
vector<ll> sorted_time, visited, what_scc;
void dfs(ll node)
{
    visited[node] = 1;
    for (auto v : g[node])
    {
        if (!visited[v])
            dfs(v);
    }
    sorted_time.push_back(node);
}
void dfs2(ll node, ll scc)
{
    visited[node] = 1;
    what_scc[node] = scc;
    for (auto v : g_rev[node])
    {
        if (!visited[v])
            dfs2(v, scc);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    g.resize(n + 1);
    g_rev.resize(n + 1);
    what_scc.resize(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g_rev[v].push_back(u);
    }

    visited.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    visited.assign(n + 1, 0);
    ll scc_cnt = 0;
    reverse(sorted_time.begin(), sorted_time.end());
    for (ll i = 0; i < sorted_time.size(); i++)
    {
        if (!visited[sorted_time[i]])
            dfs2(sorted_time[i], ++scc_cnt);
    }

    for (auto i : sorted_time)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << scc_cnt << endl;
    for (ll i = 1; i <= n; i++)
    {
        cout << what_scc[i] << " ";
    }
    cout << endl;
    return 0;
}