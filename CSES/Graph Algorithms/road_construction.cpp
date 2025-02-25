#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, set_size;
vector<pair<ll, pair<ll, ll>>> edges;
vector<ll> parent, size_rank;
ll run_max = 1;
ll find(ll x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
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
        run_max = max(run_max, size_rank[rooty]);
    }
    else
    {
        parent[rooty] = rootx;
        size_rank[rootx] += size_rank[rooty];
        run_max = max(run_max, size_rank[rootx]);
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
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        merge(u, v);
        cout << set_size << " " << run_max << "\n";
    }
    return 0;
}
