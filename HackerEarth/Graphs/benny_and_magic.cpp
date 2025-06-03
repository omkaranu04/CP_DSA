#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<vector<ll>> g, gr;
vector<array<ll, 3>> edges; // (w, u, v) format
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    g.resize(n + 1);
    gr.resize(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(v);
        gr[v].push_back(u);
        edges.push_back({w, u, v});
    }
    ll ans = 0;

    // Case 1 : min edge comes before max edge
    sort(edges.begin(), edges.end());
    vector<ll> best_min(n + 1, 1e18);
    vector<bool> used1(n + 1, false);
    queue<ll> q;
    for (auto &[w, u, v] : edges)
    {
        if (!used1[v])
        {
            used1[v] = true;
            best_min[v] = w;
            q.push(v);

            while (!q.empty())
            {
                ll x = q.front();
                q.pop();
                for (auto y : g[x])
                {
                    if (!used1[y])
                    {
                        used1[y] = 1;
                        best_min[y] = w;
                        q.push(y);
                    }
                }
            }
        }
    }
    for (auto &[w, u, v] : edges)
    {
        if (best_min[u] < 1e18)
            ans = max(ans, w - best_min[u]);
    }

    // Case 2 : max edge comes before min edge
    sort(edges.rbegin(), edges.rend());
    vector<ll> best_max(n + 1, -1e18);
    vector<bool> used2(n + 1, false);
    for (auto &[w, u, v] : edges)
    {
        if (!used2[v])
        {
            used2[v] = 1;
            best_max[v] = w;
            q.push(v);
            while (!q.empty())
            {
                ll x = q.front();
                q.pop();
                for (auto y : g[x])
                {
                    if (!used2[y])
                    {
                        used2[y] = 1;
                        best_max[y] = w;
                        q.push(y);
                    }
                }
            }
        }
    }
    for (auto &[w, u, v] : edges)
    {
        if (best_max[u] > -1e18)
            ans = max(ans, best_max[u] - w);
    }

    cout << ans;
    return 0;
}