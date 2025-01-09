#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back({v, 0});
        g[v].push_back({u, 1});
    }
    vector<ll> dist(n + 1, 1e9);
    deque<ll> q;
    q.push_front(1);
    dist[1] = 0;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop_front();
        for (auto v : g[node])
        {
            ll nn = v.first, wt = v.second;
            if (dist[node] + wt < dist[nn])
            {
                dist[nn] = dist[node] + wt;
                if (wt == 0)
                    q.push_front(nn);
                else
                    q.push_back(nn);
            }
        }
    }
    if (dist[n] == 1e9)
        cout << "-1\n";
    else
        cout << dist[n] << "\n";
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