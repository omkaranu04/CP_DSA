#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct DSU
{
    ll comps;
    vector<ll> sz, par;
    DSU(ll n) : comps(n)
    {
        sz.resize(n, 1);
        par.resize(n);
        for (ll i = 0; i < n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    bool merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
        comps--;
        return true;
    }
};
ll dist(pair<ll, ll> &a, pair<ll, ll> &b)
{
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx * dx + dy * dy;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> b(n);
    for (ll i = 0; i < n; i++)
        cin >> b[i].first >> b[i].second;

    vector<pair<ll, pair<ll, ll>>> edges;
    for (ll i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll w = dist(b[i], b[j]);
            edges.push_back({w, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll ans = 0, used = 0;
    for (auto x : edges)
    {
        ll w = x.first, u = x.second.first, v = x.second.second;
        if (dsu.merge(u, v))
        {
            ans += w;
            used++;
            if (used == n - 1)
                break;
        }
    }
    cout << ans << endl;
    return 0;
}