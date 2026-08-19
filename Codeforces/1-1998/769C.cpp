#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m, k;
vector<string> g;
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
char dir[4] = {'D', 'L', 'R', 'U'};
inline bool check(ll x, ll y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    g.resize(n);
    for (auto &x : g)
        cin >> x;
    ll sx, sy;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (g[i][j] == 'X')
            {
                sx = i;
                sy = j;
            }
        }
    }

    if (k % 2)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // BFS-type approach
    vector<vector<ll>> dist(n, vector<ll>(m, 1e18));
    queue<pair<ll, ll>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && g[nx][ny] != '*' && dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    string ans = "";
    ll x = sx, y = sy;
    for (ll i = 0; i < k; i++)
    {
        ll rem = k - i - 1;
        bool found = false;
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && g[nx][ny] != '*' && dist[nx][ny] <= rem)
            {
                ans += dir[i];
                x = nx;
                y = ny;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}