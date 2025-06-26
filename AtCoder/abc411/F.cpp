#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct FastHash
{
    size_t operator()(int x) const
    {
        static const uint64_t FIXED = chrono::steady_clock::now().time_since_epoch().count();
        return std::hash<uint64_t>{}(x ^ FIXED);
    }
};
struct DSU
{
    vector<ll> par;
    DSU(ll n = 0)
    {
        par.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    void set_parent(ll x, ll y)
    {
        par[x] = y;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> u(m + 1), v(m + 1);
    vector<unordered_set<ll, FastHash>> adj(n + 1);
    for (ll i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        adj[u[i]].insert(v[i]);
        adj[v[i]].insert(u[i]);
    }

    DSU dsu(n);
    ll no_edges = m;

    auto edge_exist = [&](ll a, ll b) -> bool
    {
        return adj[a].size() < adj[b].size() ? adj[a].count(b) : adj[b].count(a);
    };
    auto compress = [&](ll a, ll b)
    {
        if (adj[a].size() > adj[b].size())
            swap(a, b);
        no_edges--;

        for (auto x : adj[a])
        {
            if (x == b)
                continue;
            adj[x].erase(a);
            if (adj[b].insert(x).second)
                adj[x].insert(b);
            else
                no_edges--;
        }
        adj[a].clear();
        dsu.set_parent(a, b);
    };

    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        ll uu = dsu.find(u[x]);
        ll vv = dsu.find(v[x]);

        if (uu != vv && edge_exist(uu, vv))
            compress(uu, vv);
        cout << no_edges << endl;
    }
    return 0;
}