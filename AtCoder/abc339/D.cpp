#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<string> g;
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> g[i];
    vector<pair<ll, ll>> tmp;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (g[i][j] == 'P')
                tmp.push_back({i, j});
        }
    }

    bool visited[n][n][n][n];
    memset(visited, false, sizeof(visited));

    ll x1 = tmp[0].first, y1 = tmp[0].second;
    ll x2 = tmp[1].first, y2 = tmp[1].second;

    visited[x1][y1][x2][y2] = true;
    queue<tuple<ll, ll, ll, ll>> q;
    q.push({x1, y1, x2, y2});

    ll ans = 0;
    while (!q.empty())
    {
        ll sz = q.size();
        while (sz--)
        {
            auto [r1, c1, r2, c2] = q.front();
            q.pop();

            if (r1 == r2 && c1 == c2)
            {
                cout << ans;
                return 0;
            }

            for (ll i = 0; i < 4; i++)
            {
                ll nr1 = r1 + dx[i], nc1 = c1 + dy[i];
                ll nr2 = r2 + dx[i], nc2 = c2 + dy[i];

                if (nr1 < 0 || nr1 >= n || nc1 < 0 || nc1 >= n || g[nr1][nc1] == '#')
                {
                    nr1 = r1;
                    nc1 = c1;
                }
                if (nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= n || g[nr2][nc2] == '#')
                {
                    nr2 = r2;
                    nc2 = c2;
                }

                if (!visited[nr1][nc1][nr2][nc2])
                {
                    visited[nr1][nc1][nr2][nc2] = true;
                    q.push({nr1, nc1, nr2, nc2});
                }
            }
        }
        ans++;
    }
    cout << -1;
    return 0;
}