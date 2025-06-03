#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n;
vector<array<ll, 3>> edges; // w, u, v
struct DSU
{
    ll n, comps;
    vector<ll> parent, rank;

    DSU(ll _n)
    {
        n = _n;
        comps = _n;
        parent.resize(_n + 1);
        rank.resize(_n + 1, 1);
        for (ll i = 0; i <= _n; i++)
            parent[i] = i;
    }

    ll find(ll x)
    {
        if (x == parent[x])
            return x;
        else
            return parent[x] = find(parent[x]);
    }

    void merge(ll x, ll y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (rank[x] > rank[y]) // x is larger than y
        {
            rank[x] += rank[y];
            parent[y] = x;
        }
        else
        {
            rank[y] += rank[x];
            parent[x] = y;
        }
        comps--;
    }
};
void solve()
{
    edges.clear();

    cin >> n;
    DSU dsu(n);

    for (ll i = 1; i <= n - 1; i++)
    {
        ll w, u, v;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.rbegin(), edges.rend());
    ll ans = 0;
    for (auto &[w, u, v] : edges)
    {
        ll ru = dsu.find(u);
        ll rv = dsu.find(v);
        if (ru == rv)
            continue;
        ll su = dsu.rank[ru];
        ll sv = dsu.rank[rv];

        ans += (1LL * su * sv * w);
        dsu.merge(ru, rv);
    }

    cout << ans << endl;
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