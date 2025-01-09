#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m;
vector<vector<ll>> g;
vector<ll> color;
bool bfs(ll src)
{
    queue<ll> q;
    q.push(src);
    color[src] = 1;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (auto v : g[node])
        {
            if (color[v] == -1)
            {
                color[v] = 3 - color[node];
                q.push(v);
            }
            else if (color[v] == color[node])
                return false;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1, -1);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << color[i] << " ";
    return 0;
}