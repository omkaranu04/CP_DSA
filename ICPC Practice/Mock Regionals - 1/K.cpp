#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n;
vector<vector<ll>> g;
vector<ll> stsz, indp, par, outdp;
void dfs1(ll u, ll p)
{
    par[u] = p;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dfs1(v, u);
        stsz[u] += stsz[v];
    }
    stsz[u] += 1;
}
void dfs2(ll u, ll p)
{
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dfs2(v, u);
        indp[u] += indp[v];
    }
    indp[u] += stsz[u];
}
void dfs3(ll u, ll p)
{
    if (u == 1)
        outdp[u] = 0;
    else
        outdp[u] = outdp[p] + indp[p] - indp[u] - stsz[p] - stsz[u] + n;

    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dfs3(v, u);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    stsz.resize(n + 1, 0);
    par.resize(n + 1, 0);
    indp.resize(n + 1, 0);
    outdp.resize(n + 1, 0);

    dfs1(1, 0);
    dfs2(1, 0);
    dfs3(1, 0);

    // for (ll i = 1; i <= n; i++)
    //     cout << stsz[i] << " ";
    // cout << endl;
    // for (ll i = 1; i <= n; i++)
    //     cout << indp[i] << " ";
    // cout << endl;
    // for (ll i = 1; i <= n; i++)
    //     cout << outdp[i] << " ";
    // cout << endl;

    ll ans = LLONG_MIN;
    for (ll i = 1; i <= n; i++)
        ans = max(ans, indp[i] + outdp[i] + (n - stsz[i]));
    cout << ans << endl;
    return 0;
}