#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<vector<ll>> adj;
vector<ll> vis, parent;

void print_cycle(ll start, ll end)
{
    vector<ll> cycle;
    ll x = start;
    while (x != end)
    {
        cycle.push_back(x);
        x = parent[x];
    }
    cycle.push_back(end);
    cycle.push_back(start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (auto node : cycle)
        cout << node << " ";
    cout << "\n";
}

bool dfs(ll node)
{
    vis[node] = 1; // visiting

    for (auto child : adj[node])
    {
        if (vis[child] == 0)
        {
            parent[child] = node;
            if (dfs(child))
                return true;
        }
        else if (vis[child] == 1)
        {
            print_cycle(node, child);
            return true;
        }
    }

    vis[node] = 2;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (ll i = 0; i < m; ++i)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (ll i = 1; i <= n; ++i)
    {
        if (vis[i] == 0)
        {
            if (dfs(i))
            {
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
