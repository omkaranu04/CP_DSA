#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
struct DSU
{
    ll n, comp;
    vector<ll> sz, par;
    DSU(ll _n)
    {
        n = _n;
        comp = _n;
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
    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (sz[x] > sz[y])
            swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        comp--;
    }
};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<bool> edgeUsed(m + 1, false);
    DSU dsu(n);
    vector<pair<ll, ll>> edges(m + 1);
    for (ll i = 1; i <= m; i++)
        cin >> edges[i].first >> edges[i].second;
    ll q;
    cin >> q;
    vector<ll> queryEdges(q + 1);
    for (ll i = 1; i <= q; i++)
    {
        cin >> queryEdges[i];
        edgeUsed[queryEdges[i]] = true;
    }
    vector<ll> ans;
    for (ll i = 1; i <= m; i++)
        if (!edgeUsed[i])
            dsu.merge(edges[i].first, edges[i].second);
    for (ll i = q; i >= 1; i--)
    {
        ans.push_back(dsu.comp);
        ll x = edges[queryEdges[i]].first, y = edges[queryEdges[i]].second;
        dsu.merge(x, y);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << " ";
    return 0;
}