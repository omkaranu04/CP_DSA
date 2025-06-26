#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, ans;
vector<vector<pair<ll, ll>>> g;
vector<ll> wc, dep, par, path;
void dfs(ll u, ll p, ll d, ll curr)
{
    dep[u] = d;
    par[u] = p;

    path.push_back(curr);
    auto it = path.end() - lower_bound(path.begin(), path.end(), curr - wc[u]);
    ans += (ll)(it);

    for (auto &[v, w] : g[u])
    {
        if (v != p)
            dfs(v, u, d + 1, curr + w);
    }

    path.pop_back();
}
void solve()
{
    g.clear();
    wc.clear();
    dep.clear();
    par.clear();
    path.clear();

    cin >> n;
    g.resize(n + 1);
    wc.resize(n + 1);
    dep.resize(n + 1, 0);
    par.resize(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (ll i = 1; i <= n; i++)
        cin >> wc[i];

    ans = 0;
    dfs(1, 0, 0, 0);
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