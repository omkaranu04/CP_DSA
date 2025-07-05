#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll INF = 4e18;
ll n;
vector<ll> d;
vector<vector<pair<ll, ll>>> g;
vector<array<ll, 3>> edges;
vector<ll> dep, par, nval, st;
void dfs(ll u, ll p, ll dp)
{
    dep[u] = dp;
    par[p] = p;
    for (auto &[v, w] : g[u])
    {
        if (v != p)
            dfs(v, u, dp + 1);
    }
}
void dfs2(ll u, ll p, ll dp)
{
    st[u] = nval[u];
    for (auto &[v, w] : g[u])
    {
        if (v != p)
        {
            dfs2(v, u, dp + 1);
            st[u] += st[v];
        }
    }
}
/*
    (best0, best1) :    max weight in subtree if edge (p, u) NOT selected
                        and selected respectively
*/
pair<ll, ll> solve(ll u, ll p)
{
    ll base = 0;
    vector<ll> gain;

    for (auto &[v, w] : g[u])
    {
        if (v != p)
        {
            auto [f0, f1] = solve(v, u);
            base += f0;
            gain.push_back(f1 + w - f0);
        }
    }
    sort(gain.rbegin(), gain.rend());
    ll best0 = base, used = 0;
    for (ll x : gain)
    {
        if (x > 0 && used < d[u])
        {
            best0 += x;
            used++;
        }
        else
            break;
    }
    // (p, u) chosen
    ll best1 = -INF;
    if (d[u] > 0)
    {
        best1 = base;
        used = 0;
        for (ll x : gain)
        {
            if (x > 0 && used < d[u] - 1)
            {
                best1 += x;
                used++;
            }
            else
                break;
        }
    }
    return {best0, best1};
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    d.resize(n + 1);
    par.resize(n + 1);
    dep.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> d[i];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    dfs(1, 0, 0);
    nval.resize(n + 1, 0);
    for (auto &[u, v, w] : edges)
    {
        if (dep[u] > dep[v])
            nval[u] = w;
        else
            nval[v] = w;
    }
    st.resize(n + 1);
    dfs2(1, 0, 0);
    auto x = solve(1, 0);
    cout << x.first;
    return 0;
}