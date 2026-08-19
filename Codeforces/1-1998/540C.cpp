#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
vector<string> g;
vector<vector<ll>> vis;
ll r1, c1, r2, c2;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
inline bool check(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < m; }
void dfs(ll x, ll y)
{
    vis[x][y] = 1;
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny] && g[nx][ny] == '.')
            dfs(nx, ny);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n);
    for (auto &x : g)
        cin >> x;
    cin >> r1 >> c1;
    r1--;
    c1--;
    cin >> r2 >> c2;
    r2--;
    c2--;
    // condition 1 -> end = start
    if (r1 == r2 && c1 == c2)
    {
        bool existNormal = false;
        for (ll i = 0; i < 4; i++)
            if (check(r1 + dx[i], c1 + dy[i]) && g[r1 + dx[i]][c1 + dy[i]] == '.')
                existNormal = true;
        cout << (existNormal ? "YES\n" : "NO\n");
        return 0;
    }
    // condition 2 -> end = neighbour of start
    bool isNeighbor = false;
    for (ll i = 0; i < 4; i++)
        if (check(r1 + dx[i], c1 + dy[i]) && r2 == r1 + dx[i] && c2 == c1 + dy[i])
            isNeighbor = true;
    if (isNeighbor)
    {
        if (g[r2][c2] == 'X')
            cout << "YES\n";
        else
        {
            bool existNormal = false;
            for (ll i = 0; i < 4; i++)
                if (check(r2 + dx[i], c2 + dy[i]) && g[r2 + dx[i]][c2 + dy[i]] == '.')
                    existNormal = true;
            cout << (existNormal ? "YES\n" : "NO\n");
            return 0;
        }
    }
    else
    {
        vis.resize(n, vector<ll>(m, 0));
        dfs(r1, c1);
        bool reachable = false;
        for (ll i = 0; i < 4; i++)
            if (check(r2 + dx[i], c2 + dy[i]) && vis[r2 + dx[i]][c2 + dy[i]])
                reachable = true;
        if (!reachable)
            cout << "NO\n";
        else
        {
            if (g[r2][c2] == 'X')
            {
                ll existNormal = 0;
                for (ll i = 0; i < 4; i++)
                    if (check(r2 + dx[i], c2 + dy[i]) && g[r2 + dx[i]][c2 + dy[i]] == '.')
                        existNormal++;
                cout << (existNormal ? "YES\n" : "NO\n");
            }
            else
            {
                ll existNormal = 0;
                for (ll i = 0; i < 4; i++)
                    if (check(r2 + dx[i], c2 + dy[i]) && g[r2 + dx[i]][c2 + dy[i]] == '.')
                        existNormal++;
                cout << (existNormal >= 2 ? "YES\n" : "NO\n");
            }
        }
    }
    return 0;
}