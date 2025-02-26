#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll h, w;
vector<vector<char>> grid;
vector<vector<vector<ll>>> g;
#define F first
#define S second
vector<pair<ll, ll>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    ll sx, sy, gx, gy;
    grid.resize(h, vector<char>(w));
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
        }
    }
    g.resize(h, vector<vector<ll>>(w, vector<ll>(2, 1e9)));
    g[sx][sy][0] = 0;
    g[sx][sy][1] = 0;
    queue<pair<pair<ll, ll>, ll>> q;
    q.push(make_pair(make_pair(sx, sy), 0));
    q.push({make_pair(sx, sy), 1});
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        ll x = top.F.F;
        ll y = top.F.S;
        ll c = top.S;

        for (auto d : dir)
        {
            ll nx = x + d.F;
            ll ny = y + d.S;
            if (c == 0 && d.F == 0)
                continue;
            if (c == 1 && d.S == 0)
                continue;
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (grid[nx][ny] == '#')
                continue;
            if (g[nx][ny][1 - c] > g[x][y][c] + 1)
            {
                g[nx][ny][1 - c] = g[x][y][c] + 1;
                // cout << nx << " " << ny << " " << 1 - c << " " << g[nx][ny][1 - c] << endl;
                q.push({{nx, ny}, 1 - c});
            }
        }
    }
    ll ans = min(g[gx][gy][0], g[gx][gy][1]);
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}