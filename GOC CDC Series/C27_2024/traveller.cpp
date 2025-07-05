#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, x, y;
vector<vector<pair<ll, ll>>> g, rg;
vector<pair<ll, ll>> edges;
void solve()
{
    g.clear();
    rg.clear();
    edges.clear();

    cin >> n >> m;
    cin >> x >> y;
    g.resize(n + 1);
    rg.resize(n + 1);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
        edges.push_back({u, v});
    }

    // dijkstra from x to all in g
    vector<ll> dist(n + 1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, x}); // dist, node
    dist[x] = 0;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (dist[u] < d)
            continue;

        for (auto &[v, w] : g[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    // dijkstra from y to all in rg
    vector<ll> rdist(n + 1, 1e18);
    while (!pq.empty())
        pq.pop();
    pq.push({0, y});
    rdist[y] = 0;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (rdist[u] < d)
            continue;

        for (auto &[v, w] : rg[u])
        {
            if (rdist[v] > d + w)
            {
                rdist[v] = d + w;
                pq.push({rdist[v], v});
            }
        }
    }

    // for(ll i=1;i<=n;i++) cout<<dist[i]<<" ";
    // cout<<endl;
    // for(ll i=1;i<=n;i++) cout<<rdist[i]<<" ";
    // cout<<endl;

    for (auto &[u, v] : edges)
    {
        ll ans1 = dist[y];
        ll ans2 = min(dist[u], dist[v]) + min(rdist[u], rdist[v]);
        if (min(ans1, ans2) == 1e18)
            cout << -1 << " ";
        else
            cout << min(ans1, ans2) << " ";
    }
    cout << endl;
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