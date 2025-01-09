#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, q;
vector<vector<ll>> g;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    g.resize(n + 1, vector<ll>(n + 1, 1e18));
    for (ll i = 1; i <= n; i++)
    {
        g[i][i] = 0;
    }
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }
    for (ll k = 1; k <= n; k++)
    {
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= n; j++)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    while (q--)
    {
        ll u, v;
        cin >> u >> v;
        cout << (g[u][v] == 1e18 ? -1 : g[u][v]) << "\n";
    }
    return 0;
}