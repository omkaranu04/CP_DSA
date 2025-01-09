#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
ll n, m, ans = 0;
vector<vector<ll>> mat, dist;
queue<pair<ll, ll>> q;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    mat.resize(n, vector<ll>(m));
    dist.resize(n, vector<ll>(m, 1e18));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        ll x = it.first, y = it.second;
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0)
                continue;
            if (mat[nx][ny] == 1 && dist[nx][ny] == 1e18)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (mat[i][j] != 0)
                ans = max(ans, dist[i][j]);
        }
    }
    if (ans == 1e18)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}