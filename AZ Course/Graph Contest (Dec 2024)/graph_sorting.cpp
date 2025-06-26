#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<array<ll, 3>> edges;
vector<ll> pos;
struct DSU
{
    ll comps;
    vector<ll> par, sz;
    DSU(ll n) : comps(n), sz(n + 1, 1)
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
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        comps--;
    }
};
bool check(ll mid)
{
    DSU dsu(n);
    for (auto x : edges)
    {
        ll u = x[0], v = x[1], w = x[2];
        if (w >= mid)
            dsu.merge(u, v);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (dsu.find(i) != dsu.find(pos[i]))
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    pos.resize(n + 1);
    ll lo = 1, hi = 0, ans = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll pi;
        cin >> pi;
        pos[pi] = i; // 'pi' is at position 'i', (node pi has integer i holding)
    }
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        hi = max(hi, w);
    }
    bool done = true;
    for (ll i = 1; i <= n; i++)
    {
        if (pos[i] != i)
        {
            done = false;
            break;
        }
    }
    if (done)
    {
        cout << "-1";
        return 0;
    }
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    cout << ans;
    return 0;
}