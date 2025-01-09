#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, q;
vector<vector<char>> g;
vector<vector<ll>> visited;
void dfs(ll x, ll y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    if (g[x][y] == '#' || visited[x][y])
        return;
    visited[x][y] = 1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1, vector<char>(m + 1));
    visited.resize(n + 1, vector<ll>(m + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (!visited[i][j] && g[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}