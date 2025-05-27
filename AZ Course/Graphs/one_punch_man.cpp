#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<string> grid;
vector<vector<ll>> dist;
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {-1, 1, 0, 0};
bool check(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    grid.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> grid[i];
    dist.resize(n + 1, vector<ll>(m + 1, 1e18));
    deque<pair<ll, ll>> dq;
    dq.push_back({0, 0});
    dist[0][0] = 0;
    while (!dq.empty())
    {
        auto [x, y] = dq.front();
        dq.pop_front();
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny))
            {
                if (grid[nx][ny] == '.')
                {
                    if (dist[nx][ny] > dist[x][y])
                    {
                        dist[nx][ny] = dist[x][y];
                        dq.push_front({nx, ny});
                    }
                }
                else
                {
                    for (ll p = nx - 1; p <= nx + 1; p++)
                    {
                        for (ll q = ny - 1; q <= ny + 1; q++)
                        {
                            if (check(p, q))
                            {
                                if (dist[p][q] > dist[x][y] + 1)
                                {
                                    dist[p][q] = dist[x][y] + 1;
                                    dq.push_back({p, q});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dist[n - 1][m - 1];
    return 0;
}