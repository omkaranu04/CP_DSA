#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, q;
vector<vector<ll>> g, parent;
vector<ll> depth;
void dfs(ll node, ll par, ll dep)
{
    depth[node] = dep;
    parent[node][0] = par;

    for (ll i = 1; i <= 20; i++)
    {
        if (parent[node][i - 1] != -1)
            parent[node][i] = parent[parent[node][i - 1]][i - 1];
        else
            parent[node][i] = -1;
    }

    for (auto v : g[node])
    {
        if (v != par)
            dfs(v, node, dep + 1);
    }
}
ll query(ll node, ll k)
{
    ll tmp = node;
    for (ll i = 20; i >= 0; i--)
    {
        if (k & (1LL << i))
        {
            if (tmp == -1)
                return -1;
            tmp = parent[tmp][i];
        }
    }
    return tmp;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    g.resize(n + 1);
    parent.resize(n + 1, vector<ll>(21, -1));
    depth.resize(n + 1, 0);

    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        g[x].push_back(i);
        g[i].push_back(x);
    }

    dfs(1, -1, 0);

    while (q--)
    {
        ll x, k;
        cin >> x >> k;
        cout << query(x, k) << endl;
    }

    return 0;
}