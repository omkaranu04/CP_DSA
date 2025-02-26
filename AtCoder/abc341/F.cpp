#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> g;
vector<ll> w;
vector<ll> a;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    g.resize(n + 1);
    a.resize(n + 1);
    w.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i + 1];
    }
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    priority_queue<pair<ll, ll>> pq;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] > 0)
            pq.push({w[i], i});
    }
    ll ans = 0;
    while (!pq.empty())
    {
        auto [wt, x] = pq.top();
        pq.pop();
        if (a[x] == 0)
            continue;
        ll pieces = a[x];
        a[x] = 0;
        ans += pieces;
        for (ll y : g[x])
        {
            if (w[y] < w[x])
            {
                a[y] += pieces;
                pq.push({w[y], y});
            }
        }
    }
    cout << ans << endl;
    return 0;
}