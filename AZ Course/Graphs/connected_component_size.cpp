#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, m, q;
vector<vector<ll>> g, visited, component;
ll tmp_comp_size;
void dfs(ll x, ll y, ll comp)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    if (g[x][y] == 1 || visited[x][y])
        return;
    tmp_comp_size++;
    visited[x][y] = 1;
    component[x][y] = comp;
    dfs(x + 1, y, comp);
    dfs(x - 1, y, comp);
    dfs(x, y + 1, comp);
    dfs(x, y - 1, comp);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        g.clear();
        visited.clear();
        component.clear();

        cin >> n >> m;
        g.resize(n + 1, vector<ll>(m + 1));
        visited.resize(n + 1, vector<ll>(m + 1, 0));
        component.resize(n + 1, vector<ll>(m + 1, 0));
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                cin >> g[i][j];
            }
        }
        ll comp = 0;
        vector<ll> comp_size;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (!visited[i][j] && g[i][j] == 0)
                {
                    tmp_comp_size = 0;
                    dfs(i, j, ++comp);
                    comp_size.push_back(tmp_comp_size);
                }
            }
        }
        // cout << "ans : \n";
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= m; j++)
            {
                if (g[i][j] == 1)
                    cout << 1 << " ";
                else
                {
                    ll size = comp_size[component[i][j] - 1];
                    if (size == 1)
                        cout << 0 << " ";
                    else
                        cout << size << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}