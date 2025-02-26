#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<vector<pair<ll, ll>>> g;
vector<ll> a, b, x, visited, dist;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    a.resize(n + 1);
    b.resize(n + 1);
    x.resize(n + 1);
    visited.resize(n + 1, 0);
    dist.resize(n + 1, 1e18);
    for (ll i = 1; i <= n - 1; i++)
        cin >> a[i] >> b[i] >> x[i];
    for (ll i = 1; i <= n - 1; i++)
    {
        g[i].push_back({a[i], i + 1});
    }
    for (ll i = 1; i <= n - 1; i++)
    {
        g[i].push_back({b[i], x[i]});
    }
    dist[1] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll u = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = 1;
        for (auto i : g[u])
        {
            ll v = i.second;
            ll w = i.first;
            if (!visited[v] && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist[n] << endl;
    return 0;
}
// also think of a dp approach, it failed for me