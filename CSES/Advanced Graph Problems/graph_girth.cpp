#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<vector<ll>> g;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = LLONG_MAX;
    for (ll st = 1; st <= n; st++)
    {
        vector<ll> dist(n + 1, 1e18), par(n + 1, -1);

        // BFS
        queue<ll> q;
        dist[st] = 0;
        par[st] = -1;
        q.push(st);
        while (!q.empty())
        {
            ll u = q.front();
            q.pop();
            for (auto v : g[u])
            {
                // v is not visited
                if (dist[v] > dist[u] + 1 && par[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
                // if visited v and (u, v) is not parent edge
                else if (par[u] != v)
                {
                    ans = min(ans, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans);
    return 0;
}