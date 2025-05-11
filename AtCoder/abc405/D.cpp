#include <bits/stdc++.h>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dirChar[4] = {'^', 'v', '<', '>'};
const char revChar[4] = {'v', '^', '>', '<'};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i)
        cin >> grid[i];

    vector<vector<int>> dist(H, vector<int>(W, -1));
    vector<vector<int>> fromDir(H, vector<int>(W, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == 'E')
            {
                dist[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d)
        {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W)
            {
                if (grid[nx][ny] == '.' && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    fromDir[nx][ny] = d ^ 1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    vector<string> result = grid;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (grid[i][j] == '.')
            {
                int d = fromDir[i][j];
                result[i][j] = dirChar[d];
            }
        }
    }

    for (const string &row : result)
    {
        cout << row << '\n';
    }

    return 0;
}
