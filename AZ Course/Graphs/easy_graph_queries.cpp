#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, q;
vector<vector<ll>> g;
vector<ll> visited, comp_size;
ll tmp_comp_size;
void dfs(ll node, ll comp)
{
    visited[node] = comp;
    tmp_comp_size++;
    for (auto v : g[node])
    {
        if (!visited[v])
        {
            dfs(v, comp);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> q;
    g.resize(n + 1);
    visited.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll number_of_comp = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            tmp_comp_size = 0;
            dfs(i, ++number_of_comp);
            comp_size.push_back(tmp_comp_size);
        }
    }
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll X;
            cin >> X;
            // cout << "ans: ";
            cout << comp_size[visited[X] - 1] << endl;
        }
        else
        {
            ll X, Y;
            cin >> X >> Y;
            // cout << "ans: ";
            if (visited[X] == visited[Y])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}