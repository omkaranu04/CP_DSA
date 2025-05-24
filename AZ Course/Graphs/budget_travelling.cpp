#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, src, dest, C;
vector<ll> petrol;
vector<vector<pair<ll, ll>>> g;
vector<vector<ll>> dist, vis;
void dijkstra()
{
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    pq.push({0, {src, 0}});
    dist[src][0] = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        ll d = -it.first, u = it.second.first, f = it.second.second;

        if (vis[u][f])
            continue;
        vis[u][f] = 1;

        // i will see if i can reach the city with a lesser cost than what it is now
        // refuelling
        if (f < C && d + petrol[u] < dist[u][f + 1])
        {
            dist[u][f + 1] = d + petrol[u];
            pq.push({-dist[u][f + 1], {u, f + 1}});
        }

        // see if we can visit the neighboring cities with some fuel
        for (auto v : g[u])
        {
            if (f >= v.second && dist[v.first][f - v.second] > d)
            {
                dist[v.first][f - v.second] = d;
                pq.push({-dist[v.first][f - v.second], {v.first, f - v.second}});
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    petrol.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    for (ll i = 1; i <= n; i++)
        cin >> petrol[i];
    cin >> src >> dest >> C;

    dist.resize(n + 1, vector<ll>(C + 1, 1e18));
    vis.resize(n + 1, vector<ll>(C + 1, 0));

    dijkstra();

    ll ans = 1e18;
    for (ll i = 0; i <= C; i++)
        ans = min(ans, dist[dest][i]);
    cout << ans;
    return 0;
}