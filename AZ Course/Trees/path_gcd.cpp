// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// vector<ll> a, dep;
// vector<vector<ll>> g;
// vector<vector<pair<ll, ll>>> par;
// void dfs(ll node, ll parent, ll depth)
// {
//     if (parent == 0)
//         par[node][0] = {parent, a[node]};
//     else
//         par[node][0] = {parent, __gcd(a[node], a[parent])};

//     dep[node] = depth;

//     for (ll i = 1; i < 20; i++)
//     {
//         ll a1 = par[node][i - 1].first;          // (node's 2^(i-1)-th ancestor)
//         ll b1 = par[node][i - 1].second;         // (gcd of path up to 2^(i-1))
//         ll x = __gcd(par[a1][i - 1].second, b1); // (gcd along 2^i path)
//         par[node][i] = {par[a1][i - 1].first, x};
//     }

//     for (auto v : g[node])
//     {
//         if (v != parent)
//             dfs(v, node, depth + 1);
//     }

//     return;
// }
// ll lca(ll u, ll v)
// {
//     ll h = __gcd(a[u], a[v]);

//     if (dep[u] < dep[v])
//         swap(u, v);

//     for (ll i = 19; i >= 0; i++)
//     {
//         if ((dep[u] - dep[v]) & (1 << i))
//         {
//             h = __gcd(h, par[u][i].second);
//             u = par[u][i].first;
//         }
//     }

//     if (u == v)
//         return h;

//     for (ll i = 19; i >= 0; i--)
//     {
//         if (par[u][i].first != par[v][i].first)
//         {
//             h = __gcd(h, par[u][i].second);
//             h = __gcd(h, par[v][i].second);
//             u = par[u][i].first;
//             v = par[v][i].first;
//         }
//     }
//     h = __gcd(h, par[v][0].second);
//     return h;
// }
// void solve()
// {
//     g.clear();

//     ll n, q;
//     cin >> n;

//     g = vector<vector<ll>>(n + 1);
//     pair<ll, ll> p = {0, 0};
//     par = vector<vector<pair<ll, ll>>>(n + 1, vector<pair<ll, ll>>(21, p));
//     dep = vector<ll>(n + 1, 0);
//     a = vector<ll>(n + 1, 0);

//     a[0] = 1;
//     for (ll i = 1; i <= n; i++)
//     {
//         ll xx;
//         cin >> xx;
//         a[i] = xx;
//     }

//     for (ll i = 1; i < n - 1; i++)
//     {
//         ll u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }

//     dfs(1, 0, 0); // 1 is the root

//     cin >> q;
//     while (q--)
//     {
//         ll ooo, mmm;
//         cin >> ooo >> mmm;
//         cout << lca(ooo, mmm) << "\n";
//     }
//     return;
// }
// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const long long int infl = 1e18;
const int MOD = 1e9 + 7;

#define endl '\n'

void dfs(long long int node, long long int parent, long long int depth, vector<vector<long long int>> &adj, vector<vector<pair<long long int, long long int>>> &par, vector<long long int> &a, vector<long long int> &dep)
{
    if (parent == 0)
        par[node][0] = {parent, a[node]};
    else
        par[node][0] = {parent, __gcd(a[node], a[parent])};
    dep[node] = depth;

    for (long long int i = 1; i < 20; i++)
    {
        long long int a1 = par[node][i - 1].first;
        long long int b1 = par[node][i - 1].second;
        long long int x = __gcd(par[a1][i - 1].second, b1);
        par[node][i] = {par[a1][i - 1].first, x};
    }

    for (auto v : adj[node])
    {
        if (v != parent)
        {
            dfs(v, node, depth + 1, adj, par, a, dep);
        }
    }
}

long long int find_lca(long long int u, long long int v, vector<vector<pair<long long int, long long int>>> &par, vector<long long int> &a, vector<long long int> &dep)
{
    long long int h = __gcd(a[u], a[v]);

    if (dep[u] < dep[v])
        swap(u, v);

    for (long long int i = 19; i >= 0; i--)
    {
        if ((dep[u] - dep[v]) & (1 << i))
        {
            h = __gcd(h, par[u][i].second);
            u = par[u][i].first;
        }
    }

    if (u == v)
        return h;

    for (long long int i = 19; i >= 0; i--)
    {
        if (par[u][i].first != par[v][i].first)
        {
            h = __gcd(h, par[u][i].second);
            h = __gcd(h, par[v][i].second);
            u = par[u][i].first;
            v = par[v][i].first;
        }
    }
    h = __gcd(h, par[u][0].second);
    return h;
}

void solve()
{
    long long int n, q;
    cin >> n;

    vector<vector<long long int>> adj(n + 1);
    vector<vector<pair<long long int, long long int>>> par(n + 1, vector<pair<long long int, long long int>>(21, {0, 0}));
    vector<long long int> dep(n + 1, 0);
    vector<long long int> a(n + 1, 0);

    for (long long int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (long long int i = 1; i < n; i++)
    {
        long long int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, 0, 0, adj, par, a, dep);

    cin >> q;
    while (q--)
    {
        long long int u, v;
        cin >> u >> v;
        cout << find_lca(u, v, par, a, dep) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}