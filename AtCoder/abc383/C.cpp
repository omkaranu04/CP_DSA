#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll H, W, D;
    cin >> H >> W >> D;
    vector<string> grid(H);
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    vector<vector<ll>> dist(H, vector<ll>(W, -1));
    for (ll i = 0; i < H; i++)
        cin >> grid[i];
    queue<pair<ll, ll>> q;
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            if (grid[i][j] == 'H')
            {
                q.push({i, j});
                visited[i][j] = true;
                dist[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        pair<ll, ll> cell = q.front();
        q.pop();

        ll x = cell.first, y = cell.second;
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] != '#' && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    int humidifiedCount = 0;
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            if (dist[i][j] <= D && dist[i][j] != -1)
                humidifiedCount++;
        }
    }
    cout << humidifiedCount << endl;
    return 0;
}