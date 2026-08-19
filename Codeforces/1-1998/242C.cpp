#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll sx, sy, ex, ey, n;
map<ll, vector<pair<ll, ll>>> g;
map<pair<ll, ll>, ll> dist;
ll dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
bool check(ll x, ll y)
{
    if (g.find(x) == g.end())
        return false;
    for (auto &[a, b] : g[x])
        if (y >= a && y <= b)
            return true;
    return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> sx >> sy >> ex >> ey;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        ll r, a, b;
        cin >> r >> a >> b;
        g[r].push_back({a, b});
    }

    // BFS
    queue<pair<ll, ll>> q;
    q.push({sx, sy});
    dist[{sx, sy}] = 0;
    while (!q.empty())
    {
        ll x = q.front().first, y = q.front().second;
        q.pop();
        for (ll i = 0; i < 8; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && dist.find({nx, ny}) == dist.end())
            {
                dist[{nx, ny}] = dist[{x, y}] + 1;
                q.push({nx, ny});
            }
        }
    }
    if (dist.find({ex, ey}) == dist.end())
        cout << "-1\n";
    else
        cout << dist[{ex, ey}] << endl;
    return 0;
}