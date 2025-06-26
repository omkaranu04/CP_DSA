#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, s, d;
vector<vector<ll>> g;
vector<ll> vis, seen;
bool dfs(ll u)
{
    vis[u] = 1;
    for (auto v : g[u])
    {
        if (vis[v] == 0)
        {
            if (dfs(v))
                return true;
        }
        else if (vis[v] == 1)
            return true;
    }
    vis[u] = 2;
    return false;
}
void dfsSeen(ll u)
{
    seen[u] = 1;
    for (auto v : g[u])
    {
        if (!seen[v])
            dfsSeen(v);
    }
}
bool check(ll s, ll d)
{
    if (!g[d].empty())
        return false;
    if (dfs(s))
        return false;
    dfsSeen(s);
    for (ll v = 1; v <= n; v++)
    {
        if (seen[v] && g[v].empty() && v != d)
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    seen.resize(n + 1, 0);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    cin >> s >> d;

    if (check(s, d))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}