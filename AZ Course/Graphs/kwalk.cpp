#include <bits/stdc++.h>
using namespace std;
// knight moves for chessboard
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
bool check(int x, int y, int n)
{
    return x >= 1 && x <= n && y >= 1 && y <= n;
}
int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    vector<vector<int>> visited(N + 1, vector<int>(N + 1, -2));
    queue<pair<int, int>> q;
    q.push({Sx, Sy});
    visited[Sx][Sy] = 1;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (x == Fx && y == Fy)
        {
            return visited[x][y] - 1;
        }
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (check(nx, ny, N) && visited[nx][ny] == -2)
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;

        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }
    return 0;
}
