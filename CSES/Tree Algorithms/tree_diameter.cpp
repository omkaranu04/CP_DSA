#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
vector<vector<ll>> g;
vector<ll> visited, depth;
void dfs(ll u, ll d)
{
    visited[u] = 1;
    depth[u] = d;
    for (auto v : g[u])
    {
        if (!visited[v])
            dfs(v, d + 1);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    visited.resize(n + 1, 0);
    depth.resize(n + 1, 0);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, 0);
    ll src = -1, currMax = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (depth[i] > currMax)
        {
            src = i;
            currMax = depth[i];
        }
    }

    fill(visited.begin(), visited.end(), 0);
    fill(depth.begin(), depth.end(), 0);
    dfs(src, 0);

    src = -1;
    currMax = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (depth[i] > currMax)
        {
            src = i;
            currMax = depth[i];
        }
    }
    cout << currMax << endl;
    return 0;
}