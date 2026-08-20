#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
vector<vector<ll>> dist;
ll dx[16] = {-2, -2, -1, -1, 2, 2, 1, 1, 1, -1, 2, -2, 1, -1, 2, -2};
ll dy[16] = {1, -1, 2, -2, 1, -1, 2, -2, 2, 2, 1, 1, -2, -2, -1, -1};
inline bool check(ll x, ll y) { return x >= 0 && y >= 0 && x < n && y < n; }
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    dist.resize(n, vector<ll>(n, 1e18));

    // BFS
    queue<pair<ll, ll>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (ll i = 0; i < 16; i++)
        {
            ll nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && dist[nx][ny] > dist[x][y] + 1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}