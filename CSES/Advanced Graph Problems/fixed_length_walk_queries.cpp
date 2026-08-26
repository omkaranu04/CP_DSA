#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m, q;
vector<ll> g[2510];
ll dist[2510][2510][2];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    memset(dist, 0x3f, sizeof(dist));

    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (ll s = 1; s <= n; s++)
    {
        queue<pair<ll, ll>> q;
        dist[s][s][0] = 0;
        q.push({s, 0});

        while (!q.empty())
        {
            auto [u, p] = q.front();
            q.pop();

            for (auto v : g[u])
            {
                ll np = p ^ 1;
                if (dist[s][v][np] > dist[s][u][p] + 1)
                {
                    dist[s][v][np] = dist[s][u][p] + 1;
                    q.push({v, np});
                }
            }
        }
    }

    while (q--)
    {
        ll a, b, x;
        cin >> a >> b >> x;
        ll p = x % 2;
        ll d = dist[a][b][p];
        if (d <= x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}