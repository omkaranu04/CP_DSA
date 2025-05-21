#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<string> grid;
vector<vector<vector<ll>>> dist;
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {-1, 1, 0, 0};
bool check(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs(vector<pair<ll, ll>> &srcs, ll src)
{
    deque<pair<ll, ll>> dq;
    for (auto x : srcs)
    {
        dq.push_back(x);
        dist[src][x.first][x.second] = 0;
    }

    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && grid[nx][ny] != '#')
            {
                ll c = (ll)(grid[nx][ny] == '.');
                if (dist[src][nx][ny] > dist[src][x][y] + c)
                {
                    dist[src][nx][ny] = dist[src][x][y] + c;
                    if (c == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    grid.resize(n);
    dist.resize(4, vector<vector<ll>>(n, vector<ll>(m, 1e9)));
    for (ll i = 0; i < n; i++)
        cin >> grid[i];

    vector<pair<ll, ll>> srcs[4];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] >= '1' && grid[i][j] <= '3')
                srcs[grid[i][j] - '0'].push_back({i, j});
        }
    }

    bfs(srcs[1], 1);
    bfs(srcs[2], 2);
    bfs(srcs[3], 3);

    ll ans = 1e18;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] != '#')
            {
                if (dist[1][i][j] == 1e9 || dist[2][i][j] == 1e9 || dist[3][i][j] == 1e9)
                    continue;
                ll pc = dist[1][i][j] + dist[2][i][j] + dist[3][i][j];
                if (grid[i][j] == '.')
                    pc -= 2;
                ans = min(ans, pc);
            }
        }
    }

    cout << ((ans == 1e18) ? -1 : ans);
    return 0;
}