#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
vector<vector<ll>> g;
vector<ll> sz, vis;
void dfs(ll node)
{
    vis[node] = 1;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v);
            sz[node] += sz[v];
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    g.resize(n + 1);
    sz.resize(n + 1, 1);
    vis.resize(n + 1, 0);
    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }
    dfs(1);
    for (ll i = 1; i <= n; i++)
        cout << sz[i] - 1 << " ";
    return 0;
}