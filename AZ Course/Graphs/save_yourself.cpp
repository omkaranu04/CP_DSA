#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
ll n, m;
vector<vector<char>> mat;
vector<vector<ll>> distMon, distStrt;
vector<vector<bool>> visitable;
queue<pair<ll, ll>> mons, strt;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    mat.resize(n, vector<char>(m));
    distMon.resize(n, vector<ll>(m, -1));
    distStrt.resize(n, vector<ll>(m, -1));
    visitable.resize(n, vector<bool>(m, true));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == '#')
                visitable[i][j] = false;
            else if (mat[i][j] == 'M')
            {
                distMon[i][j] = 0;
                mons.push({i, j});
            }
            else if (mat[i][j] == 'A')
            {
                distStrt[i][j] = 0;
                strt.push({i, j});
            }
        }
    }
    while (!mons.empty())
    {
        auto it = mons.front();
        mons.pop();
        ll x = it.first, y = it.second;

        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0)
                continue;
            if (visitable[nx][ny] && distMon[nx][ny] == -1)
            {
                distMon[nx][ny] = distMon[x][y] + 1;
                mons.push({nx, ny});
            }
        }
    }
    while (!strt.empty())
    {
        auto it = strt.front();
        strt.pop();
        ll x = it.first, y = it.second;

        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0)
                continue;
            if (visitable[nx][ny] && distStrt[nx][ny] == -1)
            {
                distStrt[nx][ny] = distStrt[x][y] + 1;
                strt.push({nx, ny});
            }
        }
    }
    ll fx = -1, fy = -1, fd = 1e18;
    for (ll i = 0; i < n; i++)
    {
        if (visitable[i][0] && distStrt[i][0] >= 0 && (distStrt[i][0] < distMon[i][0] || distMon[i][0] == -1))
        {
            fx = i;
            fy = 0;
            fd = min(fd, distStrt[i][0]);
        }
        if (visitable[i][m - 1] && distStrt[i][m - 1] >= 0 && (distStrt[i][m - 1] < distMon[i][m - 1] || distMon[i][m - 1] == -1))
        {
            fx = i;
            fy = m - 1;
            fd = min(fd, distStrt[i][m - 1]);
        }
    }
    for (ll i = 0; i < m; i++)
    {
        if (visitable[0][i] && distStrt[0][i] >= 0 && (distStrt[0][i] < distMon[0][i] || distMon[0][i] == -1))
        {
            fx = 0;
            fy = i;
            fd = min(fd, distStrt[0][i]);
        }
        if (visitable[n - 1][i] && distStrt[n - 1][i] >= 0 && (distStrt[n - 1][i] < distMon[n - 1][i] || distMon[n - 1][i] == -1))
        {
            fx = n - 1;
            fy = i;
            fd = min(fd, distStrt[n - 1][i]);
        }
    }
    if (fd == 1e18)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << fd << "\n";
    }
    return 0;
}