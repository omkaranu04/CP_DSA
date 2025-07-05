#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
vector<vector<ll>> g;
vector<ll> a;
multiset<ll> lo, hi;
ll ans;
void rebalance()
{
    if (lo.size() > hi.size() + 1)
    {
        auto it = prev(lo.end());
        hi.insert(*it);
        lo.erase(it);
    }
    else if (lo.size() < hi.size())
    {
        auto it = hi.begin();
        lo.insert(*it);
        hi.erase(it);
    }
}
void dfs(ll u, ll p, ll d)
{
    if (lo.empty() || a[u] <= *lo.rbegin())
        lo.insert(a[u]);
    else
        hi.insert(a[u]);
    rebalance();

    if ((d & 1) == 0)
        ans += *lo.rbegin();

    for (auto v : g[u])
    {
        if (v != p)
            dfs(v, u, d + 1);
    }

    if (a[u] <= *lo.rbegin())
        lo.erase(lo.find(a[u]));
    else
        hi.erase(hi.find(a[u]));
    rebalance();
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
        a.clear();
        g.clear();
        lo.clear();
        hi.clear();

        ll n;
        cin >> n;
        a.resize(n + 1);
        g.resize(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        for (ll i = 0; i < n - 1; i++)
        {
            ll u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        ans = 0;
        dfs(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}