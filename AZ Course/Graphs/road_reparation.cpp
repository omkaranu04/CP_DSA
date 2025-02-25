#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, set_size;
vector<pair<ll, pair<ll, ll>>> edges;
vector<ll> parent, size_rank;
ll find(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]); // no path compression here
}
void merge(ll x, ll y)
{
    ll rootx = find(x), rooty = find(y);
    if (rootx == rooty)
        return;
    if (size_rank[rootx] <= size_rank[rooty])
    {
        parent[rootx] = rooty;
        size_rank[rooty] += size_rank[rootx];
    }
    else
    {
        parent[rooty] = rootx;
        size_rank[rootx] += size_rank[rooty];
    }
    set_size--;
}
void init()
{
    parent.resize(n + 1);
    size_rank.resize(n + 1, 1);
    set_size = n;
    for (ll i = 1; i <= n; i++)
        parent[i] = i;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    init();
    for (ll i = 0; i < m; i++)
    {
        ll x, y, w;
        cin >> x >> y >> w;
        edges.push_back({w, {x, y}});
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (ll i = 0; i < m; i++)
    {
        ll x = edges[i].second.first, y = edges[i].second.second, w = edges[i].first;
        if (find(x) != find(y))
        {
            merge(x, y);
            ans += w;
            if (set_size == 1)
                break;
        }
    }
    if (set_size == 1)
        cout << ans << "\n";
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}
