#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<vector<ll>> g, gr, sc_comp;
vector<ll> r, comp_id;
vector<bool> visited;
stack<ll> order;
void dfs(ll node)
{
    visited[node] = true;
    for (ll adj : g[node])
    {
        if (!visited[adj])
        {
            dfs(adj);
        }
    }
    order.push(node);
}
void dfs2(ll node, vector<ll> &comp)
{
    visited[node] = true;
    comp.push_back(node);
    for (ll adj : gr[node])
    {
        if (!visited[adj])
        {
            dfs2(adj, comp);
        }
    }
}
void remEdges(int n)
{
    vector<vector<ll>> newG(n + 1);
    for (ll u = 1; u <= n; u++)
    {
        for (ll v : gr[u])
        {
            if (comp_id[u] != comp_id[v])
            {
                newG[u].push_back(v);
            }
        }
    }
    gr = newG;
}
ll chain(ll node, vector<vector<ll>> &gr, vector<ll> &dp)
{
    if (dp[node] != -1)
        return dp[node];
    ll ans = 0;
    for (ll adj : gr[node])
    {
        ans = max(ans, chain(adj, gr, dp) + 1);
    }
    return dp[node] = ans;
}
void solve()
{
    g.clear();
    gr.clear();
    sc_comp.clear();
    comp_id.clear();
    r.clear();
    visited.clear();
    order = stack<ll>();

    cin >> n;
    g.assign(n + 1, vector<ll>());
    gr.assign(n + 1, vector<ll>());
    comp_id.resize(n + 1);
    r.resize(n + 1);
    visited.assign(n + 1, false);
    for (ll i = 1; i <= n; i++)
    {
        cin >> r[i];
        g[i].push_back(r[i]);  // seedha
        gr[r[i]].push_back(i); // ulta
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    visited.assign(n + 1, false);
    while (!order.empty())
    {
        ll node = order.top();
        order.pop();

        if (!visited[node])
        {
            vector<ll> comp;
            dfs2(node, comp);
            sc_comp.push_back(comp);
            for (ll v : comp)
            {
                comp_id[v] = sc_comp.size() - 1;
            }
        }
    }
    remEdges(n);
    vector<ll> dp(n + 1, -1);
    ll ans = 0;
    for (auto &comp : sc_comp)
    {
        for (ll node : comp)
        {
            ans = max(ans, chain(node, gr, dp));
        }
    }
    ans += 2;
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