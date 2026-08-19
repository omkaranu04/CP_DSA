#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
vector<string> g;
vector<vector<ll>> vis;
vector<ll> dx = {1, -1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};
inline bool check(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < m; }
void dfs(ll x, ll y)
{
    vis[x][y] = 1;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny] && g[nx][ny] == '.')
            dfs(nx, ny);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n);
    for (auto &x : g)
        cin >> x;
    vis.resize(n, vector<ll>(m, 0));
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (!vis[i][j] && g[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}