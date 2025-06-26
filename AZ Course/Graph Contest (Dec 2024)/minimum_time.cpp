#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
ll dy[8] = {0, 0, 1, -1, -1, 1, -1, 1};
bool check(ll x, ll y, ll n, ll m)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    char g[n][m];
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll dist[n][m];
    memset(dist, -1, sizeof(dist));
    queue<pair<ll, ll>> q;
    q.push({a, b});
    dist[a][b] = 0;
    while (!q.empty())
    {
        auto x = q.front();
        ll cx = x.first, cy = x.second;
        ll d = dist[cx][cy];
        q.pop();

        for (ll i = 0; i < 8; i++)
        {
            ll nx = cx + dx[i], ny = cy + dy[i];
            if (check(nx, ny, n, m) && g[nx][ny] == '.' && dist[nx][ny] == -1)
            {
                dist[nx][ny] = d + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[c][d] << endl;
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