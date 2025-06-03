// IMPORTANT
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n;
vector<ll> a;
vector<vector<ll>> g;
vector<ll> subtree_cost, subtree_sum;
vector<ll> final_cost;
void dfs1(ll node, ll par)
{
    subtree_sum[node] = a[node];
    subtree_cost[node] = 0;
    for (auto v : g[node])
    {
        if (v != par)
        {
            dfs1(v, node);
            subtree_sum[node] += subtree_sum[v];
            subtree_cost[node] += (subtree_sum[v] + subtree_cost[v]);
        }
    }
}
void dfs2(ll node, ll par)
{
    for (auto v : g[node])
    {
        if (v != par)
        {
            ll parcost = final_cost[node] - (subtree_cost[v] + subtree_sum[v]);
            ll remsum = subtree_sum[1] - subtree_sum[v];
            final_cost[v] = subtree_cost[v] + parcost + remsum;

            dfs2(v, node);
        }
    }
}
void solve()
{
    a.clear();
    g.clear();

    cin >> n;
    a.resize(n + 1);
    g.resize(n + 1);
    subtree_sum.resize(n + 1, 0);  // sum to store subtree sum of a[]
    subtree_cost.resize(n + 1, 0); // cost is according to their definition
    final_cost.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1, 0);

    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << "(" << subtree_sum[i] << "," << subtree_cost[i] << ")" << endl;
    // }

    final_cost[1] = subtree_cost[1];
    dfs2(1, 0);

    // for (ll i = 1; i <= n; i++)
    //     cout << final_cost[i] << " ";
    // cout << endl;

    ll ans1 = *min_element(final_cost.begin() + 1, final_cost.end());
    ll ans2 = *max_element(final_cost.begin() + 1, final_cost.end());

    cout << ans2 << " " << ans1 << endl;
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