#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<vector<ll>> g;
vector<ll> depth, parent, subtreesz, ansx;
// ansx -> stores the sum of depths of nodes in subtrees
void dfs(ll u, ll p, ll d)
{
    depth[u] = d;
    parent[u] = p;
    subtreesz[u] = 1;
    ansx[u] = depth[u];

    for (ll v : g[u])
    {
        if (v != p)
        {
            dfs(v, u, d + 1);
            subtreesz[u] += subtreesz[v];
            ansx[u] += ansx[v];
        }
    }
}
void dfs2(ll u, ll p)
{
    for (auto v : g[u])
    {
        if (v != p)
        {
            ansx[v] = ansx[u] - subtreesz[v] + (n - subtreesz[v]);
            dfs2(v, u);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    depth.resize(n + 1, 0);
    parent.resize(n + 1, 0);
    subtreesz.resize(n + 1, 0);
    ansx.resize(n + 1, 0);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);
    dfs2(1, 0);

    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << parent[i] << " " << depth[i] << " " << subtreesz[i] << " " << ansx[i] << endl;
    // }
    for (ll i = 1; i <= n; i++)
    {
        cout << ansx[i] << " ";
    }

    return 0;
}