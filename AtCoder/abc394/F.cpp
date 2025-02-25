#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n;
vector<vector<ll>> g;
vector<ll> deg, deg4, visited, lar_subt;
ll dfs(ll node, ll par, ll &cnt)
{
    cnt++;
    visited[node] = 1;
    vector<ll> tmp;

    for (auto v : g[node])
    {
        if (v == par)
            continue;
        if (deg4[v]) // if degree 4 then only explore
        {
            tmp.push_back(dfs(v, node, cnt));
        }
    }

    if (tmp.size() == 0)
    {
        lar_subt[node] = 1;
        return 1;
    }

    sort(tmp.rbegin(), tmp.rend());
    while (tmp.size() < 4)
        tmp.push_back(0);

    lar_subt[node] = tmp[0] + tmp[1] + tmp[2] + tmp[3] + 1;
    return lar_subt[node] - tmp[3];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    deg.resize(n + 1, 0);
    deg4.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    lar_subt.resize(n + 1, 0);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    for (ll i = 1; i <= n; i++)
    {
        if (deg[i] >= 4)
            deg4[i] = 1;
    }
    ll res = -1;
    for (ll i = 1; i <= n; i++)
    {
        ll cnt = 0;
        if (visited[i])
            continue;
        if (deg4[i])
        {
            ll tmp = dfs(i, -1, cnt);
        }
    }
    for (ll i = 1; i <= n; i++)
        res = max(res, lar_subt[i]);
        
    if (res == 0)
        cout << -1 << endl;
    else if (res == 1)
        cout << 5 << endl;
    else if (res == 2)
        cout << 8 << endl;
    else
        cout << 8 + 3 * (res - 2) << endl;
    return 0;
}