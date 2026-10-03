#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n;
    vector<ll> sz, par;
    DSU(const ll _n)
    {
        n = _n;
        sz.resize(n + 1, 1);
        par.resize(n + 1);
        for (ll i = 0; i <= n; i++)
            par[i] = i;
    }
    ll find(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool unite(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        if (x > y)
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        return true;
    }
};
struct Edge
{
    ll x, y;
    ll s;
};
bool comp(Edge a, Edge b)
{
    return a.s < b.s;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        vector<Edge> edges(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> edges[i].x >> edges[i].y >> edges[i].s;
        }
        sort(edges.begin(), edges.end(), comp);
        DSU dsu(n);
        ll used = 0, maxi = LLONG_MIN, ans = 0;
        for (auto e : edges)
        {
            ll x = e.x, y = e.y, s = e.s;
            if (dsu.unite(x, y))
            {
                used++;
                maxi = max(maxi, s);
                if (s > k)
                    ans += (s - k);
                if (used == n - 1)
                    break;
            }
        }
        if (maxi <= k)
        {
            // cout << "here: ";
            ll mini = LLONG_MAX;
            for (ll i = 0; i < m; i++)
                mini = min(mini, abs(k - edges[i].s));
            cout << mini << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}