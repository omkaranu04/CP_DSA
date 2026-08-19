#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll h, w;
vector<string> g;
vector<vector<ll>> dist;
vector<vector<pair<ll, ll>>> mp(26);
vector<bool> used(26, false);
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
inline bool check(ll x, ll y)
{
    return x >= 0 && x < h && y >= 0 && y < w;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> h >> w;
    g.resize(h);
    dist.resize(h, vector<ll>(w, 1e18));
    for (auto &x : g)
        cin >> x;
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            if (g[i][j] >= 'a' && g[i][j] <= 'z')
                mp[g[i][j] - 'a'].push_back({i, j});
        }
    }

    // BFS
    queue<pair<ll, ll>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        // teleport
        if (g[x][y] >= 'a' && g[x][y] <= 'z')
        {
            ll c = g[x][y] - 'a';
            if (!used[c])
            {
                used[c] = true;
                for (auto [nx, ny] : mp[c])
                {
                    if (check(nx, ny) && dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        // move
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (!check(nx, ny) || g[nx][ny] == '#')
                continue;
            if (dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (dist[h - 1][w - 1] == 1e18)
        cout << "-1\n";
    else
        cout << dist[h - 1][w - 1] << endl;
    return 0;
}