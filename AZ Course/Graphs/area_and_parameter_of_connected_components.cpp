#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
ll n, temp_comp_area;
vector<vector<char>> grid;
vector<vector<ll>> comp;
vector<vector<bool>> visited;
vector<ll> comp_areas, comp_perimeters;

void dfs(ll x, ll y, ll comp_num, ll &peri)
{
    if (x >= n || y >= n || x < 0 || y < 0 || grid[x][y] == '.')
    {
        peri++;
        return;
    }
    if (visited[x][y])
        return;

    visited[x][y] = true;
    comp[x][y] = comp_num;
    temp_comp_area++;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        dfs(nx, ny, comp_num, peri);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    grid.resize(n, vector<char>(n));
    comp.resize(n, vector<ll>(n, 0));
    visited.resize(n, vector<bool>(n, false));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < n; j++)
            cin >> grid[i][j];

    ll comp_num = 0;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (!visited[i][j] && grid[i][j] == '#')
            {
                temp_comp_area = 0;
                ll perimeter = 0;
                dfs(i, j, ++comp_num, perimeter);
                comp_areas.push_back(temp_comp_area);
                comp_perimeters.push_back(perimeter);
            }
        }
    }

    ll max_area = 0, min_perimeter = LLONG_MAX;
    for (ll i = 0; i < comp_areas.size(); i++)
    {
        if (comp_areas[i] > max_area ||
            (comp_areas[i] == max_area && comp_perimeters[i] < min_perimeter))
        {
            max_area = comp_areas[i];
            min_perimeter = comp_perimeters[i];
        }
    }

    cout << max_area << " " << min_perimeter << "\n";
    return 0;
}