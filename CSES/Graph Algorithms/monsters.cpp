#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<string> g;
vector<vector<ll>> dist_mons, dist_pers;
vector<pair<ll, ll>> mons;
vector<vector<pair<ll, ll>>> par;
pair<ll, ll> st, fin, curr;
ll dx[4] = {1, 0, 0, -1};
ll dy[4] = {0, -1, 1, 0};
inline bool check(ll x, ll y) { return x >= 0 && y >= 0 && x < n && y < m; }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n);
    dist_mons.resize(n, vector<ll>(m, 1e18));
    dist_pers.resize(n, vector<ll>(m, 1e18));
    par.resize(n, vector<pair<ll, ll>>(m, {-1, -1}));
    for (auto &x : g)
        cin >> x;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (g[i][j] == 'M')
                mons.push_back({i, j});
            if (g[i][j] == 'A')
                st = {i, j};
        }
    }

    // Monster BFS
    queue<pair<ll, ll>> q;
    for (auto x : mons)
    {
        dist_mons[x.first][x.second] = 0;
        q.push(x);
    }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && g[nx][ny] != '#' && dist_mons[nx][ny] > dist_mons[x][y] + 1)
            {
                dist_mons[nx][ny] = dist_mons[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Person BFS
    while (!q.empty())
        q.pop();
    q.push(st);
    dist_pers[st.first][st.second] = 0;
    par[st.first][st.second] = {-1, -1};
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && g[nx][ny] != '#' && dist_pers[nx][ny] > dist_pers[x][y] + 1)
            {
                dist_pers[nx][ny] = dist_pers[x][y] + 1;
                par[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    // Check for end-point
    fin = {-1, -1};
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (dist_pers[i][j] < dist_mons[i][j])
                {
                    fin = {i, j};
                    break;
                }
            }
        }
        if (fin != make_pair(-1LL, -1LL))
            break;
    }

    if (fin == make_pair(-1LL, -1LL))
    {
        cout << "NO\n";
        return 0;
    }

    string ans = "";
    curr = fin;
    while (curr != st)
    {
        auto [x, y] = curr;
        auto [px, py] = par[x][y];
        if (px == x - 1)
            ans += 'D';
        if (px == x + 1)
            ans += 'U';
        if (py == y - 1)
            ans += 'R';
        if (py == y + 1)
            ans += 'L';
        curr = {px, py};
    }
    cout << "YES\n"
         << ans.length() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}