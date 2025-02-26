#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> g;
vector<ll> parent, visited;
ll startw = -1, endw = -1;
bool dfs(ll node, ll par)
{
    visited[node] = 1;
    for (auto v : g[node])
    {
        if (v == par)
            continue;

        if (!visited[v])
        {
            parent[v] = node;
            if (dfs(v, node))
                return true;
        }
        else
        {
            startw = v;
            endw = node;
            return true;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i, -1))
        {
            vector<ll> ans;
            ans.push_back(startw);
            for (ll v = endw; v != startw; v = parent[v])
                ans.push_back(v);
            ans.push_back(startw);
            cout << ans.size() << endl;
            for (auto x : ans)
                cout << x << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}