#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {-1, 1, 0, 0};
ll n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
bool check(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void dfs(ll x, ll y)
{
    visited[x][y] = true;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.')
            dfs(nx, ny);
    }
}
int main()
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '.')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}