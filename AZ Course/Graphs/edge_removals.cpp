#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, q, set_size;
vector<ll> parent, rank_s;
ll find(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
void merge(ll x, ll y)
{
    ll xroot = find(x), yroot = find(y);
    if (xroot == yroot)
        return;
    if (rank_s[xroot] <= rank_s[yroot])
    {
        parent[xroot] = yroot;
        rank_s[yroot] += rank_s[xroot];
    }
    else
    {
        parent[yroot] = xroot;
        rank_s[xroot] += rank_s[yroot];
    }
    set_size--;
}
void reset()
{
    for (ll i = 1; i <= n; i++)
    {
        parent[i] = i;
        rank_s[i] = 1;
    }
    set_size = n;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    parent.resize(n + 1);
    rank_s.resize(n + 1, 1);
    set_size = n;
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    vector<pair<ll, pair<ll, ll>>> edges(m);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        edges[i] = {i + 1, {u, v}};
    }
    vector<ll> touched(m + 1, 0);
    vector<pair<ll, ll>> queries;
    // store the queries;
    for (ll i = 1; i <= q; i++)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x;
            cin >> x;
            touched[x-1] = 1;
            queries.push_back({1, x-1});
        }
        if (type == 2)
        {
            queries.push_back({2, -1});
        }
    }
    for (ll i = 0; i < m; i++)
    {
        if (!touched[i])
        {
            merge(edges[i].second.first, edges[i].second.second);
        }
    }
    vector<ll> ans;
    for (ll i = q - 1; i >= 0; i--)
    {
        if (queries[i].first == 1)
        {
            ll x = queries[i].second;
            merge(edges[x].second.first, edges[x].second.second);
        }
        if (queries[i].first == 2)
        {
            ans.push_back(set_size);
        }
    }
    for (ll i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}