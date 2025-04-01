#include <bits/stdc++.h> // Warnsdorffs Algorithm
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ll long long int
#define endl "\n"
ll sx, sy;
ll dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
ll dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
vector<pair<ll, ll>> path;
vector<vector<ll>> vis(8, vector<ll>(8, 0));
bool check(ll x, ll y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
        return true;
    return false;
}
ll getDegree(ll x, ll y)
{
    ll cnt = 0;
    for (ll i = 0; i < 8; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny])
            cnt++;
    }
    return cnt;
}
bool take_move(ll x, ll y)
{
    ll min_deg_x = -1, min_deg_y = -1, min_deg = 9;
    for (ll i = 0; i < 8; i++)
    {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (check(nx, ny) && !vis[nx][ny])
        {
            ll deg = getDegree(nx, ny);
            if (deg < min_deg)
            {
                min_deg = deg;
                min_deg_x = nx;
                min_deg_y = ny;
            }
        }
    }
    if (min_deg_x == -1 && min_deg_y == -1)
        return false;
    vis[min_deg_x][min_deg_y] = 1;
    path.push_back({min_deg_x, min_deg_y});
    return true;
}
bool find_tour()
{
    path.push_back({sx, sy});
    vis[sx][sy] = 1;
    for (ll i = 0; i < 63; i++)
    {
        if (!take_move(path.back().first, path.back().second))
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> sx >> sy;
    // swap(sx, sy);
    sx--, sy--;
    vector<vector<ll>> ans(8, vector<ll>(8, 0));
    if (find_tour())
    {
        for (ll i = 0; i < 64; i++)
        {
            ans[path[i].second][path[i].first] = i + 1;
        }
        for (ll i = 0; i < 8; i++)
        {
            for (ll j = 0; j < 8; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}