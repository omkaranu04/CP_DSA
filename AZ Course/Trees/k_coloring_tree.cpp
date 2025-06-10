#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<vector<pair<ll, ll>>> g(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // consider root 1
    vector<ll> parent(n + 1, -1), order;
    queue<ll> q;
    parent[1] = 0;
    order.push_back(1);
    q.push(1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto &[v, w] : g[u])
        {
            if (parent[v] != -1)
                continue;
            parent[v] = u;
            q.push(v);
            order.push_back(v);
        }
    }

    vector<ll> dp0(n + 1, 0), dp1(n + 1, 0);
    for (ll i = n - 1; i >= 0; i--)
    {
        ll u = order[i];

        ll baseSum = 0;
        vector<ll> gains;

        for (auto &[v, w] : g[u])
        {
            if (v == parent[u])
                continue;
            baseSum += dp0[v];
            ll gain = dp1[v] + w - dp0[v];
            if (gain > 0)
                gains.push_back(gain);
        }

        sort(gains.rbegin(), gains.rend());
        vector<ll> ps(gains.size() + 1, 0);
        for (ll i = 0; i < gains.size(); i++)
            ps[i + 1] = ps[i] + gains[i];

        dp0[u] = baseSum + ps[min(k, (ll)gains.size())];
        dp1[u] = baseSum + ps[(k > 0 ? min(k - 1, (ll)gains.size()) : 0)];
    }

    cout << dp0[1] << endl;
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