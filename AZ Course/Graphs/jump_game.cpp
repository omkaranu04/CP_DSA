#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, a, b, src, sz;
vector<ll> arr;
map<ll, vector<ll>> mp;
vector<vector<pair<ll, ll>>> g;
void dijkstra(ll src)
{
    vector<ll> vis(sz, 0), dist(sz, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();

        if (vis[u])
            continue;
        vis[u] = 1;

        for (auto [v, w] : g[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (ll i = 1; i <= n; i++)
        cout << dist[i] << " ";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> a >> b;
    arr.resize(n + 1);

    for (ll i = 1; i <= n; i++)
        cin >> arr[i];
    cin >> src;
    for (ll i = 1; i <= n; i++)
        mp[arr[i]].push_back(i);

    sz = n + mp.size() + 5;
    g.resize(sz);

    for (ll i = 1; i <= n; i++)
    {
        if (i != 1)
            g[i].push_back({i - 1, b});
        if (i != n)
            g[i].push_back({i + 1, b});
    }
    ll snode = n + 1;
    for (auto x : mp)
    {
        ll num = x.first;
        vector<ll> conn = x.second;
        for (auto i : conn)
        {
            g[snode].push_back({i, a});
            g[i].push_back({snode, 0});
        }
        snode++;
    }

    dijkstra(src);

    return 0;
}