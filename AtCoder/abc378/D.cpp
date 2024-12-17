#include <bits/stdc++.h>
using namespace std;

int H, W, K;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int ans = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void rec(int r, int c, int k)
{
    if (k == K)
    {
        ans++;
        return;
    }

    visited[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] == '.' && !visited[nr][nc])
        {
            rec(nr, nc, k + 1);
        }
    }
    visited[r][c] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> H >> W >> K;
    grid.resize(H, vector<char>(W));
    visited.resize(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (grid[i][j] == '.')
            {
                rec(i, j, 0);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
