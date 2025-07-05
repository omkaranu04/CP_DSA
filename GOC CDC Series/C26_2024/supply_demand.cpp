#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<ll> d, s, td, ts;
vector<vector<ll>> g;
void dfs(ll u, ll p)
{
    td[u] = d[u];
    ts[u] = s[u];
    for (auto v : g[u])
    {
        if (v != p)
        {
            dfs(v, u);
            td[u] += td[v];
            ts[u] += ts[v];
        }
    }
}
void solve()
{
    g.clear();
    d.clear();
    s.clear();
    ts.clear();
    td.clear();

    cin >> n;
    g.resize(n + 1);
    d.resize(n + 1);
    s.resize(n + 1);
    td.resize(n + 1);
    ts.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> d[i];
    for (ll i = 1; i <= n; i++)
        cin >> s[i];

    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    dfs(1, 0);
    for (ll i = 1; i <= n; i++)
        ans += llabs(td[i] - ts[i]);
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