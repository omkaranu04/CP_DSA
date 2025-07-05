#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<vector<ll>> g;
vector<ll> dep, par;
vector<bool> ondia;
void dfs(ll u, ll d, ll p)
{
    dep[u] = d;
    par[u] = p;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, d + 1, u);
    }
}
ll dfs2(ll u, ll p)
{
    ll mdep = 0;
    for (auto v : g[u])
    {
        if (v == p || ondia[v])
            continue;
        mdep = max(mdep, 1 + dfs2(v, u));
    }
    return mdep;
}
void solve()
{
    g.clear();
    dep.clear();
    par.clear();
    ondia.clear();

    cin >> n;
    g.resize(n + 1);
    dep.resize(n + 1);
    par.resize(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll p1, p2, p3;
    dfs(1, 0, 0);
    p1 = 1;
    for (ll i = 1; i <= n; i++)
        if (dep[i] > dep[p1])
            p1 = i;
    p2 = 1;
    dfs(p1, 0, 0);
    for (ll i = 1; i <= n; i++)
        if (dep[i] > dep[p2])
            p2 = i;

    ondia.resize(n + 1, false);
    vector<ll> path;
    ll tmp = p2;
    while (tmp != 0)
    {
        path.push_back(tmp);
        ondia[tmp] = true;
        tmp = par[tmp];
    }
    ll maxdep = 0;
    for (ll node : path)
    {
        for (auto v : g[node])
        {
            if (!ondia[v])
                maxdep = max(maxdep, 1 + dfs2(v, node));
        }
    }
    ll ans = path.size() + maxdep;
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