#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, x;
vector<string> grid;
vector<vector<bool>> vis;
bool check(ll i, ll j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
ll dx[5] = {1, -1, 0, 0, 0};
ll dy[5] = {0, 0, 1, -1, 0};
ll rec(ll cx, ll cy, ll t)
{
    if (abs(cx) + abs(cy) > x - t)
        return -1e18;
    if (t == x)
    {
        if (cx == 0 && cy == 0)
            return 0;
        else
            return -1e18;
    }
    ll ans = -1e18;
    for (ll i = 0; i < 5; i++)
    {
        ll nx = cx + dx[i], ny = cy + dy[i];
        if (check(nx, ny) && grid[nx][ny] == '1')
        {
            bool f = !vis[nx][ny];
            vis[nx][ny] = true;
            ll tmp = rec(nx, ny, t + 1);
            if (tmp != -1e18)
                ans = max(ans, tmp + (ll)f);
            vis[nx][ny] = f ? false : true;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> x;
    grid.resize(n);
    vis.resize(n + 1, vector<bool>(m + 1, false));
    for (ll i = 0; i < n; i++)
        cin >> grid[i];
    vis[0][0] = true;
    ll ans = rec(0, 0, 0) + 1;
    cout << ans;
    return 0;
}