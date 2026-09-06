#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll dx[4] = {0, 0, 1, -1};
ll dy[4] = {1, -1, 0, 0};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    vector<string> g(n);
    for (auto &x : g)
        cin >> x;

    vector<vector<ll>> c(n, vector<ll>(m, -1));
    vector<ll> pics;
    ll comp = 0;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (g[i][j] != '.' || c[i][j] != -1)
                continue;

            ll p = 0;
            queue<pair<ll, ll>> q;
            q.push({i, j});
            c[i][j] = comp;

            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for (ll k = 0; k < 4; k++)
                {
                    ll nx = x + dx[k], ny = y + dy[k];
                    if (g[nx][ny] == '*')
                        p++;
                    else if (g[nx][ny] == '.' && c[nx][ny] == -1)
                    {
                        q.push({nx, ny});
                        c[nx][ny] = comp;
                    }
                }
            }
            pics.push_back(p);
            comp++;
        }
    }
    while (k--)
    {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << pics[c[x][y]] << endl;
    }
    return 0;
}