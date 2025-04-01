#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
vector<vector<ll>> g;
vector<ll> visited;
ll n, m;
void dfs(ll node)
{
    visited[node] = 1;
    for (auto x : g[node])
    {
        if (!visited[x])
            dfs(x);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            comp++;
        }
    }
    cout << m - n + comp << endl;
    return 0;
}