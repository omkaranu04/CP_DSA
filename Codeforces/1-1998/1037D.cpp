#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    vector<ll> depth(n + 1, -1);
    vector<ll> parent(n + 1, -1);

    // BFS
    queue<ll> q;
    depth[1] = 0;
    parent[1] = 0;
    q.push(1);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (depth[v] != -1)
                continue;
            depth[v] = depth[u] + 1;
            parent[v] = u;
            q.push(v);
        }
    }
    if (a[1] != 1)
    {
        cout << "No\n";
        return 0;
    }

    vector<ll> position(n + 1);
    for (ll i = 1; i <= n; i++)
        position[a[i]] = i;

    for (ll i = 2; i <= n; i++)
    {
        ll prev = a[i - 1], curr = a[i];
        if (depth[curr] < depth[prev])
        {
            cout << "No\n";
            return 0;
        }
        if (depth[curr] == depth[prev])
        {
            if (position[parent[curr]] > position[parent[curr]])
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    return 0;
}