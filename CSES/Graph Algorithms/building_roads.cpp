#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
vector<vector<ll>> g;
vector<ll> comp, vis;
void dfs(ll x, ll c)
{
    vis[x] = 1;
    comp[x] = c;
    for (auto v : g[x])
    {
        if (!vis[v])
            dfs(v, c);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    g.resize(n + 1);
    comp.resize(n + 1);
    vis.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll c = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, ++c);
    }
    vector<ll> nodes(n + 1);
    for (ll i = 1; i <= n; i++)
        nodes[comp[i]] = i;
    cout << c - 1 << endl;
    for (ll i = 1; i <= c - 1; i++)
        cout << nodes[i] << " " << nodes[i + 1] << endl;
    return 0;
}