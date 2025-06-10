#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<vector<pair<ll, ll>>> g;
vector<ll> x, vis;
ll ans;
ll dfs(ll u)
{
    vis[u] = 1;
    ll tot = x[u];
    for (auto &[v, w] : g[u])
    {
        if (!vis[v])
        {
            ll tmp = dfs(v);
            ans += llabs(tmp) * w;
            tot += tmp;
        }
    }
    return tot;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    x.resize(n + 1);
    vis.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> x[i];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    ans = 0;
    dfs(1);
    cout << ans << endl;
    return 0;
}