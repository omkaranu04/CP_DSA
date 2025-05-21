#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

ll dxx[4] = {1, -1, 0, 0};
ll dyy[4] = {0, 0, 1, -1};

bool check(ll x, ll y, ll n, ll m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < m; j++)
            cin >> grid[i][j];
    ll sx = 0, sy = 0, dx = 0, dy = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] == 'R')
            {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'E')
            {
                dx = i, dy = j;
            }
        }
    }
    vector<vector<ll>> dist(n, vector<ll>(m, -1));
    queue<pair<ll, ll>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            ll nx = it.first + dxx[i];
            ll ny = it.second + dyy[i];
            if (check(nx, ny, n, m) && (grid[nx][ny] == 'O' || grid[nx][ny] == 'E') && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[it.first][it.second] + 1;
                if (nx == dx && ny == dy)
                {
                    cout << dist[dx][dy] << endl;
                    return 0;
                }
                q.push({nx, ny});
            }
        }
    }
    cout << dist[dx][dy] << endl;
    return 0;
}
