#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
vector<ll> marked;
vector<pair<pair<ll, char>, pair<ll, ll>>> queries;
vector<vector<ll>> g;
struct DSU
{
    vector<ll> par, rank;
    ll comps;
    DSU(ll _n)
    {
        par.resize(_n + 1);
        rank.resize(_n + 1, 1);
        for (ll i = 0; i < _n; i++)
            par[i] = i;
        comps = _n;
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
        if (rank[x] < rank[y])
            swap(x, y); // x has larger rank
        par[y] = x;
        rank[x] += rank[y];
        comps--;
    }
    bool connected(ll x, ll y)
    {
        return find(x) == find(y);
    }
};
void solve()
{
    g.clear();
    queries.clear();

    ll n, m, q;
    cin >> n >> m >> q;
    g.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 0; i < m + q; i++)
    {
        char t;
        ll u, v;
        cin >> t >> u >> v;
        queries.push_back({{i, t}, {u, v}});
    }
    DSU city(n);
    vector<string> ans;
    for (ll i = m + q - 1; i >= 0; i--)
    {
        char t = queries[i].first.second;
        ll u = queries[i].second.first, v = queries[i].second.second;
        if (t == 'q')
        {
            if (u == 0 && v == 0)
            {
                ans.push_back(to_string(city.comps));
            }
            else
            {
                if (city.connected(u, v))
                    ans.push_back("YES");
                else
                    ans.push_back("NO");
            }
        }
        if (t == 'd')
        {
            city.merge(u, v);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << endl;
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