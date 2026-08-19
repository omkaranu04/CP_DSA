#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
vector<string> g;
vector<vector<ll>> dist;
vector<vector<pair<ll, ll>>> par;
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
inline bool check(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < m; }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, vector<ll>(m, 1e18));
    par.resize(n, vector<pair<ll, ll>>(m));
    for (auto &x : g)
        cin >> x;
    pair<ll, ll> start, finish;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (g[i][j] == 'A')
                start = {i, j};
            if (g[i][j] == 'B')
                finish = {i, j};
        }
    }

    // BFS
    queue<pair<ll, ll>> q;
    dist[start.first][start.second] = 0;
    par[start.first][start.second] = {-1, -1};
    q.push(start);
    while (!q.empty())
    {
        auto [x, y] = q.front();
        // cout << "x " << x << " y " << y << endl;
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && g[nx][ny] != '#' && dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                par[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    if (dist[finish.first][finish.second] == 1e18)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        string ans = "";
        pair<ll, ll> curr = finish;
        while (curr != start)
        {
            pair<ll, ll> prev = par[curr.first][curr.second];
            if (prev.first + 1 == curr.first)
                ans += 'D';
            if (prev.first - 1 == curr.first)
                ans += 'U';
            if (prev.second + 1 == curr.second)
                ans += 'R';
            if (prev.second - 1 == curr.second)
                ans += 'L';
            curr = prev;
        }
        cout << ans.length() << endl;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}