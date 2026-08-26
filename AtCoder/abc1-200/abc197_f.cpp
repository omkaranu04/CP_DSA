#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
struct Edge
{
    ll to;
    char c;
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n + 1);
    vector<tuple<ll, ll, char>> edges;
    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        char c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
        edges.push_back({a, b, c});
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, -1));
    queue<pair<ll, ll>> q;
    dist[1][n] = 0;
    q.push({1, n});

    while (!q.empty())
    {
        auto [u, v] = q.front();
        q.pop();
        for (auto &e1 : g[u])
        {
            ll x = e1.to;
            char c1 = e1.c;
            for (auto &e2 : g[v])
            {
                ll y = e2.to;
                char c2 = e2.c;

                if (c1 != c2)
                    continue;
                if (dist[x][y] == -1)
                {
                    dist[x][y] = dist[u][v] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    ll ans = LLONG_MAX;
    // even-length palindrome
    for (ll i = 1; i <= n; i++)
        if (dist[i][i] != -1)
            ans = min(ans, 2 * 1LL * dist[i][i]);

    // odd-length palindrome
    for (auto &[u, v, c] : edges)
    {
        if (dist[u][v] != -1)
            ans = min(ans, 2 * dist[u][v] + 1);
        if (dist[v][u] != -1)
            ans = min(ans, 2 * dist[v][u] + 1);
    }
    cout << (ans == LLONG_MAX ? -1 : ans);
    return 0;
}