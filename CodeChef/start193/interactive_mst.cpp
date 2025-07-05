#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll mincut(ll n, vector<vector<ll>> &adj)
{
    vector<ll> vtx(n);
    for (ll i = 0; i < n; i++)
        vtx[i] = i;
    ll ans = LLONG_MAX;
    for (ll ph = n; ph > 1; ph--)
    {
        vector<ll> w(ph, 0), added(ph, 0);
        ll prev = -1;
        for (ll i = 0; i < ph; i++)
        {
            ll sel = -1;
            for (ll j = 0; j < ph; j++)
            {
                if (!added[j] && (sel == -1 || w[j] > w[sel]))
                    sel = j;
            }

            added[sel] = 1;

            if (i == ph - 1)
            {
                ans = min(ans, w[sel]);
                for (ll j = 0; j < ph; j++)
                {
                    adj[vtx[prev]][vtx[j]] += adj[vtx[sel]][vtx[j]];
                    adj[vtx[j]][vtx[prev]] += adj[vtx[j]][vtx[sel]];
                }
                vtx.erase(vtx.begin() + sel);
            }
            else
            {
                prev = sel;
                for (ll j = 0; j < ph; j++)
                {
                    if (!added[j])
                        w[j] += adj[vtx[sel]][vtx[j]];
                }
            }
        }
    }
    return ans;
}
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<array<ll, 3>> edges;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w});
    }

    vector<vector<ll>> g(n), adj(n, vector<ll>(n, 0));
    for (auto &e : edges)
    {
        ll u = e[0], v = e[1], w = e[2];
        if (w == 0)
        {
            g[u].push_back(v);
            g[v].push_back(u);
            adj[u][v] = adj[v][u] = 1;
        }
    }

    vector<ll> vis(n, 0);
    queue<ll> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (vis[v] == 1)
                continue;
            vis[v] = 1;
            q.push(v);
        }
    }
    bool connected = true;
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            connected = false;
            break;
        }
    }
    if (!connected)
        cout << 0 << endl;
    else
    {
        ll ans = mincut(n, adj);
        cout << ans << endl;
    }
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