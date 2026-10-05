#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct Edge
{
    ll u, v, t;
};
vector<vector<ll>> g, rg;
vector<Edge> edges;
vector<ll> order, used, comp;
void dfs1(ll u)
{
    used[u] = 1;
    for (auto v : g[u])
    {
        if (!used[v])
            dfs1(v);
    }
    order.push_back(u);
}
void dfs2(ll u, ll k)
{
    comp[u] = k;
    for (auto v : rg[u])
    {
        if (comp[v] == -1)
            dfs2(v, k);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll N, Q;
    cin >> N >> Q;
    g.resize(N);
    rg.resize(N);
    for (ll i = 0; i < Q; i++)
    {
        ll t, u, v;
        cin >> t >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        rg[v].push_back(u);
        edges.push_back({u, v, t});
    }
    used.resize(N, 0);
    for (ll i = 0; i < N; i++)
    {
        if (!used[i])
            dfs1(i);
    }
    comp.resize(N, -1);
    reverse(order.begin(), order.end());
    ll k = 0;
    for (auto u : order)
    {
        if (comp[u] == -1)
        {
            dfs2(u, k);
            k++;
        }
    }

    // check for a strict edge in the SCC
    for (auto &[u, v, t] : edges)
    {
        if (t == 1 && (comp[u] == comp[v]))
        {
            cout << "No\n";
            return 0;
        }
    }

    // create a DAG of SCCs
    vector<vector<pair<ll, ll>>> dag(k);
    vector<ll> indeg(k, 0);
    for (auto &[u, v, t] : edges)
    {
        ll cu = comp[u], cv = comp[v];
        if (cu == cv)
            continue;
        dag[cu].push_back({cv, t});
        indeg[cv]++;
    }
    // topological DP
    queue<ll> q;
    for (ll i = 0; i < k; i++)
        if (indeg[i] == 0)
            q.push(i);
    vector<ll> dp(k, 1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto &[v, t] : dag[u])
        {
            dp[v] = max(dp[v], dp[u] + t);
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    cout << "Yes\n";
    for (ll i = 0; i < N; i++)
        cout << dp[comp[i]] << " ";
    cout << endl;
    return 0;
}