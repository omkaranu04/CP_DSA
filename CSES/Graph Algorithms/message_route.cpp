#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m;
vector<vector<ll>> g;
vector<ll> dis, par;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    dis.resize(n + 1, 1e18);
    par.resize(n + 1, -1);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // BFS
    queue<ll> q;
    q.push(1);
    dis[1] = 0;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : g[u])
        {
            if (dis[u] + 1 < dis[v])
            {
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    if (dis[n] == 1e18)
        cout << "IMPOSSIBLE";
    else
    {
        vector<ll> ans;
        ll u = n;
        while (u != -1)
        {
            ans.push_back(u);
            u = par[u];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
