#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll, ll>
#define F first
#define S second
vector<vector<char>> grid;
vector<vector<bool>> visitable, visited;
vector<vector<ll>> monster_dist, person_dist;
vector<vector<pll>> parent;
vector<pll> path;
ll n, m;
pll person, out_point;
vector<pll> monsters;
string ans;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};

bool valid(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m && visitable[x][y];
}
void monster_BFS()
{
    queue<pll> q;
    for (auto mons : monsters)
    {
        q.push(mons);
        monster_dist[mons.F][mons.S] = 0;
        visited[mons.F][mons.S] = true;
    }
    while (!q.empty())
    {
        pll curr = q.front();
        q.pop();
        ll x = curr.F, y = curr.S;
        for (ll i = 0; i < 4; i++)
        {
            ll xn = x + dx[i], yn = y + dy[i];
            if (valid(xn, yn) && !visited[xn][yn])
            {
                visited[xn][yn] = true;
                monster_dist[xn][yn] = monster_dist[x][y] + 1;
                q.push({xn, yn});
            }
        }
    }
}
void person_BFS()
{
    queue<pll> q;
    q.push(person);
    visited[person.F][person.S] = true;
    person_dist[person.F][person.S] = 0;
    while (!q.empty())
    {
        pll curr = q.front();
        q.pop();
        ll x = curr.F, y = curr.S;
        for (ll i = 0; i < 4; i++)
        {
            ll xn = x + dx[i], yn = y + dy[i];
            if (valid(xn, yn) && !visited[xn][yn])
            {
                visited[xn][yn] = true;
                person_dist[xn][yn] = person_dist[x][y] + 1;
                q.push({xn, yn});
                parent[xn][yn] = {x, y};
            }
        }
    }
}

void pathstring()
{
    while (out_point != person)
    {
        pll p = parent[out_point.F][out_point.S];
        if (p.F == out_point.F)
        {
            if (p.S < out_point.S)
            {
                ans += 'R';
            }
            else
            {
                ans += 'L';
            }
        }
        else
        {
            if (p.F < out_point.F)
            {
                ans += 'D';
            }
            else
            {
                ans += 'U';
            }
        }
        out_point = p;
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visitable.resize(n, vector<bool>(m, true));
    visited.resize(n, vector<bool>(m, false));
    monster_dist.resize(n, vector<ll>(m, 1e9));
    person_dist.resize(n, vector<ll>(m, 1e9));
    parent.resize(n, vector<pll>(m, {-1, -1}));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == '#')
                visitable[i][j] = false;
            if (grid[i][j] == 'A')
                person = {i, j};
            if (grid[i][j] == 'M')
                monsters.push_back({i, j});
        }
    }
    out_point = {-1, -1};
    monster_BFS();
    fill(visited.begin(), visited.end(), vector<bool>(m, false));
    person_BFS();
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (person_dist[i][j] < monster_dist[i][j])
                {
                    out_point = {i, j};
                    break;
                }
            }
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cout << monster_dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "---\n";
    // for (ll i = 0; i < n; i++)
    // {
    //     for (ll j = 0; j < m; j++)
    //     {
    //         cout << person_dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "---\n";
    // for (const auto &x : BFSTree)
    // {
    //     cout << "(" << x.first.first << ", " << x.first.second << ") -> ";
    //     for (const auto &y : x.second)
    //     {
    //         cout << "(" << y.first << ", " << y.second << "), ";
    //     }
    //     cout << endl;
    // }
    // cout << person.F << " " << person.S << endl;
    // cout << out_point.F << " " << out_point.S << endl;
    // for (auto x : path)
    // {
    //     cout << x.F << " " << x.S << endl;
    // }
    if (out_point == pll{-1, -1})
    {
        cout << "NO" << endl;
        return 0;
    }
    pathstring();
    cout << "YES" << endl;
    cout << ans.length() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}