#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<pair<ll, ll>>> g, rg;
vector<pair<pair<ll, ll>, ll>> edges;
vector<ll> dist, rdist, vis;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    rg.resize(n + 1);
    dist.resize(n + 1, 1e18);
    rdist.resize(n + 1, 1e18);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
        edges.push_back({{u, v}, w});
    }

    vis.resize(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq1;
    pq1.push({0, 1});
    dist[1] = 0;
    while (!pq1.empty())
    {
        ll u = pq1.top().second;
        ll d = pq1.top().first;
        pq1.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &x : g[u])
        {
            ll v = x.first;
            ll w = x.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq1.push({dist[v], v});
            }
        }
    }

    vis.clear();
    vis.resize(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq2;
    pq2.push({0, n});
    rdist[n] = 0;
    while (!pq2.empty())
    {
        ll u = pq2.top().second;
        ll d = pq2.top().first;
        pq2.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto &x : rg[u])
        {
            ll v = x.first;
            ll w = x.second;
            if (rdist[v] > rdist[u] + w)
            {
                rdist[v] = rdist[u] + w;
                pq2.push({rdist[v], v});
            }
        }
    }

    ll ans = 1e18;
    for (auto e : edges)
    {
        ll u = e.first.first;
        ll v = e.first.second;
        ll w = e.second;
        ans = min(ans, dist[u] + rdist[v] + w / 2);
    }
    cout << ans << endl;
    return 0;
}