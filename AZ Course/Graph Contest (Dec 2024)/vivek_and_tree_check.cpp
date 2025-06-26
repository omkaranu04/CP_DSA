#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<vector<ll>> g;
vector<ll> dep, par;
void dfs(ll u, ll p, ll d)
{
    dep[u] = d;
    par[u] = p;
    for (auto v : g[u])
    {
        if (v != p)
            dfs(v, u, d + 1);
    }
}
bool dfs2(ll u, ll p, ll d, vector<ll> &part, ll tar)
{
    if (g[u].size() == 1)
    {
        if (d == tar)
        {
            part[u] = 1;
            return true;
        }
        return false;
    }
    bool found = false;
    for (auto v : g[u])
    {
        if (v != p)
        {
            if (dfs2(v, u, d + 1, part, tar))
            {
                part[u] = 1;
                found = true;
            }
        }
    }
    return found;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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

    dfs(1, 0, 0);
    ll maxdp = 1;
    for (ll i = 1; i <= n; i++)
    {
        if (dep[i] > dep[maxdp])
            maxdp = i;
    }
    dfs(maxdp, 0, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (dep[i] > dep[maxdp])
            maxdp = i;
    }
    ll dia = dep[maxdp];
    if (dia % 2 == 0)
    {
        ll c = maxdp;
        for (ll i = 0; i < dia / 2; i++)
            c = par[c];
        vector<ll> part(n + 1, 0);
        bool tmp = dfs2(c, 0, 0, part, dia / 2);
        bool avail = false;
        for (ll i = 1; i <= n; i++)
        {
            if (part[i] == 0)
            {
                avail = true;
                break;
            }
        }
        if (avail)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else
    {
        ll c1 = maxdp, c2;
        for (ll i = 0; i < dia / 2; i++)
            c1 = par[c1];
        c2 = par[c1];
        vector<ll> part(n + 1, 0);
        bool tmp1 = dfs2(c1, c2, 0, part, dia / 2);
        bool tmp2 = dfs2(c2, c1, 0, part, dia / 2);
        bool avail = false;
        for (ll i = 1; i <= n; i++)
        {
            if (part[i] == 0)
            {
                avail = true;
                break;
            }
        }
        if (avail)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}