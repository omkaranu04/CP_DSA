#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
struct DSU
{
    ll comps;
    vector<ll> par, sz;
    DSU(ll n)
    {
        par.resize(n);
        sz.resize(n, 1);
        for (ll i = 0; i < n; i++)
            par[i] = i;
        comps = n;
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
void solve()
{
    ll n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    DSU dsu(n);
    vector<ll> a(m), b(m);

    for (ll i = 0; i < m; i++)
        cin >> a[i];

    for (ll i = 0; i < m; i++)
        cin >> b[i];

    for (ll i = 0; i < m; i++)
        dsu.merge(a[i], b[i]);

    vector<vector<char>> x(n);
    for (ll i = 0; i < n; i++)
        x[dsu.find(i)].push_back(s[i]);
    for (auto &v : x)
        sort(v.rbegin(), v.rend());
    for (ll i = 0; i < n; i++)
    {
        cout << x[dsu.find(i)].back();
        x[dsu.find(i)].pop_back();
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}