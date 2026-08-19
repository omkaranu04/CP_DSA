#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
vector<vector<ll>> g;
vector<ll> vis;
bool dfs(ll node, ll team)
{
    vis[node] = team;
    for (auto v : g[node])
    {
        if (vis[v] == 0)
        {
            if (team == 1)
            {
                if (!dfs(v, 2))
                    return false;
            }
            else
            {
                if (!dfs(v, 1))
                    return false;
            }
        }
        else if (vis[v] == team)
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
    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i, 1))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << vis[i] << " ";
    return 0;
}