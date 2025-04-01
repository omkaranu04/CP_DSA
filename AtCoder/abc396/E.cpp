#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

ll n, m;
vector<vector<pair<ll, ll>>> g;
vector<ll> vals, visited, ans;

bool bfs(ll start, vector<ll> &comp)
{
    queue<ll> q;
    q.push(start);
    visited[start] = 1;
    comp.push_back(start);

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (auto [v, w] : g[node])
        {
            if (vals[v] == -1)
            {
                vals[v] = vals[node] ^ w;
                visited[v] = 1;
                comp.push_back(v);
                q.push(v);
            }
            else if (vals[v] != (vals[node] ^ w))
            {
                cout << -1 << endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    g.resize(n + 1);
    vals.resize(n + 1, -1);
    visited.resize(n + 1, 0);
    ans.resize(n + 1, 0);

    for (ll i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    for (ll i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            vals[i] = 0;
            vector<ll> comp;
            if (!bfs(i, comp))
                return 0;

            for (ll bit = 0; bit < 30; bit++)
            {
                ll cnt = 0;
                for (ll j : comp)
                {
                    if (vals[j] & (1 << bit))
                        cnt++;
                }

                if (cnt < (ll)comp.size() - cnt)
                {
                    for (ll j : comp)
                    {
                        if (vals[j] & (1 << bit))
                            ans[j] |= (1 << bit);
                    }
                }
                else
                {
                    for (ll j : comp)
                    {
                        if (!(vals[j] & (1 << bit)))
                            ans[j] |= (1 << bit);
                    }
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
