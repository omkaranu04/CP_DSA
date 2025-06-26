#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<vector<pair<ll, ll>>> g;
vector<ll> edges;
vector<pair<ll, ll>> ans;

void dfs(ll u, ll parent, bool alter)
{
    for (auto &[v, idx] : g[u])
    {
        if (edges[idx])
            continue;
        edges[idx] = true;
        if (alter)
        {
            ans.push_back({u, v});
            dfs(v, u, false);
        }
        else
        {
            ans.push_back({v, u});
            dfs(v, u, true);
        }
    }
}

void solve()
{
    g.clear();
    ans.clear();

    cin >> n;
    g.resize(n + 1);
    edges.assign(n - 1, 0);

    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back({v, i - 1});
        g[v].push_back({u, i - 1});
    }

    ll root = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (g[i].size() == 2)
        {
            root = i;
            break;
        }
    }

    if (root == -1)
    {
        cout << "NO\n";
        return;
    }

    ll s1 = g[root][0].first, s2 = g[root][1].first;
    edges[g[root][0].second] = 1;
    edges[g[root][1].second] = 1;
    ans.push_back({s1, root});
    ans.push_back({root, s2});

    dfs(s1, root, true);
    dfs(s2, root, false);

    cout << "YES\n";
    for (auto &[v, u] : ans)
        cout << u << " " << v << endl;
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