#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
vector<vector<int>> s;
bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs01()
{
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    deque<pair<int, int>> dq;
    dq.push_front({0, 0});
    dist[0][0] = 0;

    while (!dq.empty())
    {
        int x = dq.front().first, y = dq.front().second;
        dq.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            // to check if move is aligned with the grid
            int moveAlign = !(i + 1 == s[x][y]);
            if (check(nx, ny) && dist[x][y] + moveAlign < dist[nx][ny])
            {
                dist[nx][ny] = dist[x][y] + moveAlign;
                if (moveAlign)
                    dq.push_back({nx, ny});
                else
                    dq.push_front({nx, ny}); // cheaper move
            }
        }
    }
    cout << (dist[n - 1][m - 1] == 1e9 ? -1 : dist[n - 1][m - 1]) << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    s.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> s[i][j];
    }
    bfs01();
    return 0;
}