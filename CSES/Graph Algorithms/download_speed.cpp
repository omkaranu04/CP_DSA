#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<vector<ll>> g, capacity;
vector<ll> parent;
ll flow = 0;
bool reachable(ll source, ll sink)
{
    fill(parent.begin(), parent.end(), -1);
    queue<ll> q;
    q.push(source);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            ll cap = capacity[u][v];
            if (cap <= 0 || parent[v] != -1)
                continue;
            parent[v] = u;
            q.push(v);
        }
    }
    return parent[sink] != -1;
}
void find_flow(ll source, ll sink)
{
    while (reachable(source, sink))
    {
        ll node = sink;
        ll curr_flow = 1e18;
        while (node != source)
        {
            ll par = parent[node];
            curr_flow = min(curr_flow, capacity[par][node]);
            node = par;
        }
        node = sink;
        while (node != source)
        {
            ll par = parent[node];
            capacity[par][node] -= curr_flow;
            capacity[node][par] += curr_flow;
            node = par;
        }
        flow += curr_flow;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n);
    capacity.resize(n, vector<ll>(n, 0));
    parent.resize(n);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        capacity[u][v] += c;
    }
    ll source, sink;
    source = 0, sink = n - 1;
    find_flow(source, sink);
    cout << flow << endl;
    return 0;
}