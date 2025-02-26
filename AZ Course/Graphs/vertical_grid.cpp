#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, k, tmp_cmp_size;
vector<string> tgrid;
vector<vector<int>> grid, visited, comp;
vector<int> comp_sizes;
bool check(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void gravity()
{
    for (int j = 0; j < 10; j++)
    {
        int top = n - 1, bottom = n - 1;
        while (top >= 0)
        {
            while (top >= 0 && grid[top][j] == 0)
                top--;
            if (top >= 0)
                grid[bottom--][j] = grid[top--][j];
        }
        while (bottom >= 0)
            grid[bottom--][j] = 0;
    }
}
void dfs(int x, int y, int cmp, int color)
{
    visited[x][y] = 1;
    comp[x][y] = cmp;
    tmp_cmp_size++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny, n, 10) && !visited[nx][ny] && grid[nx][ny] == color)
            dfs(nx, ny, cmp, color);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    tgrid.resize(n);
    grid.resize(n, vector<int>(10));
    for (int i = 0; i < n; i++)
        cin >> tgrid[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 10; j++)
            grid[i][j] = tgrid[i][j] - '0';
    bool flag = true;
    while (flag)
    {
        comp_sizes.clear();
        comp.clear();
        visited.clear();

        comp.resize(n, vector<int>(10));
        visited.assign(n, vector<int>(10, 0));
        int no_of_comp = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    tmp_cmp_size = 0;
                    dfs(i, j, ++no_of_comp, grid[i][j]);
                    comp_sizes.push_back(tmp_cmp_size);
                }
            }
        }
        vector<int> comp_sizes_copy = comp_sizes;
        sort(comp_sizes.begin(), comp_sizes.end());
        auto it = lower_bound(comp_sizes.begin(), comp_sizes.end(), k);
        if (it == comp_sizes.end())
            flag = false;
        else
        {
            for (int i = 0; i < comp_sizes_copy.size(); i++)
            {
                if (comp_sizes_copy[i] >= k)
                {
                    for (int j = 0; j < n; j++)
                    {
                        for (int l = 0; l < 10; l++)
                        {
                            if (comp[j][l] == i + 1)
                                grid[j][l] = 0;
                        }
                    }
                }
            }
            gravity();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << grid[i][j];
        cout << endl;
    }
    return 0;
}