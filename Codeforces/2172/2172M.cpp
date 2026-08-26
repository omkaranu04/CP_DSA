#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m, k;
vector<ll> a, dist, vis;
vector<vector<ll>> g;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    a.resize(n + 1);
    g.resize(n + 1);
    dist.resize(n + 1, 1e18);
    vis.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // BFS
    queue<ll> q;
    q.push(1);
    dist[1] = 0;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    map<ll, ll> mp;
    for (ll i = 1; i <= k; i++)
        mp[i] = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll k = a[i];
        mp[k] = max(mp[k], dist[i]);
    }
    for (auto x : mp)
        cout << x.second << " ";
    return 0;
}