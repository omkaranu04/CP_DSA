#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[4] = {0, 0, -1, 1}; // LRUD
ll dy[4] = {-1, 1, 0, 0};
ll n, m, sx, sy, fx, fy;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<pair<ll, ll>>> parent;
string ans;
bool check(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs()
{
    queue<pair<ll, ll>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;
    parent[sx][sy] = {-1, -1};

    while (!q.empty())
    {
        ll x = q.front().first, y = q.front().second;
        q.pop();

        if (x == fx && y == fy)
        {
            cout << "YES\n";
            pair<ll, ll> curr = {x, y};

            while (curr != make_pair(sx, sy))
            {
                pair<ll, ll> p = parent[curr.first][curr.second];
                if (p.first == curr.first)
                {
                    if (p.second < curr.second)
                        ans.push_back('R');
                    else
                        ans.push_back('L');
                }
                else
                {
                    if (p.first < curr.first)
                        ans.push_back('D');
                    else
                        ans.push_back('U');
                }
                curr = p;
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            cout << ans << endl;
            return;
        }

        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && !visited[nx][ny] && grid[nx][ny] != '#')
            {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    cout << "NO\n";
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    parent.resize(n, vector<pair<ll, ll>>(m, {-1, -1}));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'B')
            {
                fx = i;
                fy = j;
            }
        }
    }
    bfs();
    return 0;
}