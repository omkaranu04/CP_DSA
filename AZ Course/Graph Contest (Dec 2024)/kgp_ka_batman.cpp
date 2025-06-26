#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, R, c, r;
vector<vector<ll>> g;
void dfs(ll u, vector<ll> &vis, ll &x)
{
    vis[u] = 1;
    x++;
    for (auto v : g[u])
    {
        if (!vis[v])
            dfs(v, vis, x);
    }
}
void solve()
{
    g.clear();

    cin >> N >> R >> c >> r;
    g.resize(N + 1);
    for (ll i = 0; i < R; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (r >= c)
    {
        cout << c * N << endl;
        return;
    }
    ll cmps = 0;
    vector<ll> sz, vis(N + 1, 0);
    for (ll i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            ll tmp = 0;
            dfs(i, vis, tmp);
            sz.push_back(tmp);
            cmps++;
        }
    }
    ll ans = cmps * c;
    for (auto x : sz)
        ans += (r * (x - 1));
    cout << ans << endl;
    return;
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