#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, m, c, r;
vector<vector<ll>> g;
vector<ll> comps, vis;
void dfs(ll u, ll &sz)
{
    vis[u] = 1;
    sz++;
    for (auto v : g[u])
    {
        if (!vis[v])
            dfs(v, sz);
    }
}
void solve()
{
    g.clear();
    vis.clear();
    comps.clear();

    cin >> n >> m >> c >> r;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (r > c)
    {
        cout << n * c << endl;
        return;
    }
    ll num = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ll sz = 0;
            dfs(i, sz);
            comps.push_back(sz);
            num++;
        }
    }
    ll ans = 0;
    for (auto x : comps)
    {
        ans += c;
        ans += (x - 1) * r;
    }
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