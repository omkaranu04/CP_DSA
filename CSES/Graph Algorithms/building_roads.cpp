#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> g;
vector<bool> visited;
vector<ll> comp;
void dfs(ll node, ll c)
{
    visited[node] = true;
    comp[node] = c;
    for (auto v : g[node])
    {
        if (!visited[v])
            dfs(v, c);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1, false);
    comp.resize(n + 1, -1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll c = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, ++c);
    }
    // for (auto i : comp)
    //     cout << i << " ";
    // cout << endl;
    // cout << c << endl;
    vector<ll> ans(c + 1);
    for (ll i = 1; i <= n; i++)
        ans[comp[i]] = i;
    cout << c - 1 << endl;
    for (ll i = 1; i <= c - 1; i++)
        cout << ans[i] << " " << ans[i + 1] << endl;
    return 0;
}