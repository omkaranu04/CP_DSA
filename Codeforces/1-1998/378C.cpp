#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m, k;
vector<string> g;
vector<vector<ll>> vis;
vector<pair<ll, ll>> order;
inline bool check(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < m; }
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0, 0, 1, -1};
void dfs(ll x, ll y)
{
    vis[x][y] = 1;
    order.push_back({x, y});
    for (ll i = 0; i < 4; i++)
    {
        ll nx = x + dx[i], ny = y + dy[i];
        if (check(nx, ny) && g[nx][ny] == '.' && !vis[nx][ny])
            dfs(nx, ny);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    g.resize(n);
    vis.resize(n, vector<ll>(m, 0));
    for (auto &x : g)
        cin >> x;
    vector<string> ans(n);
    ans = g;
    ll sx = -1, sy = -1;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (g[i][j] == '.')
            {
                sx = i;
                sy = j;
                break;
            }
        }
    }
    dfs(sx, sy);
    for (ll i = 0; i < k; i++)
    {
        auto [x, y] = order.back();
        ans[x][y] = 'X';
        order.pop_back();
    }
    for (auto x : ans)
        cout << x << endl;
    return 0;
}