#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
bool check(ll x, ll y, ll n, ll m)
{
    return x >= 0 && x <= n && y >= 0 && y <= m;
}
void solve()
{
    ll n, m, x, y, d;
    cin >> n >> m >> x >> y >> d;
    if (d == 0)
    {
        cout << ((x == 0 && y == 0) ? 0 : -1) << endl;
        return;
    }
    vector<pair<ll, ll>> pytha;
    for (ll i = 1; i <= 1000; i++)
    {
        for (ll j = 1; j <= 1000; j++)
        {
            if (i * i + j * j == d * d)
            {
                pytha.push_back({i, j});
                pytha.push_back({-i, j});
                pytha.push_back({i, -j});
                pytha.push_back({-i, -j});
            }
        }
    }
    pytha.push_back({-d, 0});
    pytha.push_back({d, 0});
    pytha.push_back({0, -d});
    pytha.push_back({0, d});

    vector<vector<ll>> dist(n + 1, vector<ll>(m + 1, -1));
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty())
    {
        auto [cx, cy] = q.front();
        q.pop();
        ll cd = dist[cx][cy];
        for (auto &[dx, dy] : pytha)
        {
            ll nx = cx + dx, ny = cy + dy;
            if (check(nx, ny, n, m) && dist[nx][ny] == -1)
            {
                dist[nx][ny] = cd + 1;
                if (nx == x && ny == y)
                {
                    cout << dist[nx][ny] << endl;
                    return;
                }
                q.push({nx, ny});
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}