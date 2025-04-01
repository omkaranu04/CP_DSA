#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int H, W, N;
vector<vector<int>> grid;
vector<vector<int>> coins;
vector<vector<int>> dp;
vector<vector<char>> parent;

void bfs_01()
{
    deque<pii> dq;
    dp[1][1] = grid[1][1]; // Start from (1,1)
    dq.push_front({1, 1});

    while (!dq.empty())
    {
        auto [r, c] = dq.front();
        dq.pop_front();

        // Try moving Right (R)
        if (c + 1 <= W)
        {
            int new_coins = dp[r][c] + grid[r][c + 1];
            if (new_coins > dp[r][c + 1])
            {
                dp[r][c + 1] = new_coins;
                parent[r][c + 1] = 'R';
                if (grid[r][c + 1])
                    dq.push_front({r, c + 1});
                else
                    dq.push_back({r, c + 1});
            }
        }

        // Try moving Down (D)
        if (r + 1 <= H)
        {
            int new_coins = dp[r][c] + grid[r + 1][c];
            if (new_coins > dp[r + 1][c])
            {
                dp[r + 1][c] = new_coins;
                parent[r + 1][c] = 'D';
                if (grid[r + 1][c])
                    dq.push_front({r + 1, c});
                else
                    dq.push_back({r + 1, c});
            }
        }
    }
}

string reconstruct_path()
{
    string path = "";
    int r = H, c = W;
    while (r > 1 || c > 1)
    {
        path += parent[r][c];
        if (parent[r][c] == 'R')
            c--;
        else
            r--;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> N;
    grid.assign(H + 1, vector<int>(W + 1, 0));
    dp.assign(H + 1, vector<int>(W + 1, -1e9));
    parent.assign(H + 1, vector<char>(W + 1, 0));

    // Read coin positions
    for (int i = 0; i < N; i++)
    {
        int r, c;
        cin >> r >> c;
        grid[r][c] = 1;
    }

    bfs_01();
    cout << dp[H][W] << "\n";
    cout << reconstruct_path() << "\n";

    return 0;
}