#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> parent, ranks;
vector<vector<array<ll, 3>>> e_edges;
void init(int n)
{
    parent.resize(n);
    ranks.resize(n, 1);
    e_edges.resize(n);
    for (ll i = 0; i < n; i++)
        parent[i] = i;
}
ll find(ll x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
bool same(ll x, ll y)
{
    return find(x) == find(y);
}
void merge(ll x, ll y)
{
    ll rootx = find(x), rooty = find(y);
    if (rootx == rooty)
        return;
    if (ranks[rootx] < ranks[rooty])
        swap(rootx, rooty);
    parent[rooty] = rootx;
    if (ranks[rootx] == ranks[rooty])
        ranks[rootx]++;
    // merge the extra edges of y to x
    e_edges[rootx].insert(e_edges[rootx].end(), e_edges[rooty].begin(), e_edges[rooty].end());
    e_edges[rooty].clear();
}
void addEdge(ll root, ll x, ll y, ll idx)
{
    e_edges[root].push_back({x, y, idx});
}
vector<array<ll, 3>> getEdges(ll x)
{
    return e_edges[x];
}
bool isRoot(ll x)
{
    return x == find(x);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    init(n);
    for (ll i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        if (same(x, y))
            addEdge(find(x), x, y, i);
        else
            merge(x, y);
    }
    vector<pair<ll, ll>> comp;
    for (ll i = 0; i < n; i++)
    {
        if (isRoot(i))
        {
            comp.push_back({e_edges[i].size(), i});
        }
    }
    sort(comp.begin(), comp.end());
    reverse(comp.begin(), comp.end());
    cout << comp.size() - 1 << endl;
    ll pos = 1;
    for (auto [_, root] : comp)
    {
        for (auto [x, y, idx] : getEdges(root))
        {
            if (pos < comp.size())
                cout << idx + 1 << " " << x + 1 << " " << comp[pos++].second + 1 << endl;
        }
    }
    return 0;
}