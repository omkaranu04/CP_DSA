#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
vector<vector<pair<ll, ll>>> g;
vector<ll> deg, vis, color;
void dfs(ll u, ll bannedColor)
{
    vis[u] = 1;
    ll nxtColor = 1;
    for (auto &[v, edgeID] : g[u])
    {
        if (vis[v])
            continue;
        if (nxtColor == bannedColor)
            nxtColor++;
        color[edgeID] = nxtColor;
        dfs(v, nxtColor);
        nxtColor++;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    deg.resize(n + 1, 0);
    vis.resize(n + 1, 0);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }
    color.resize(n, 0);
    ll k = 0;
    for (ll i = 1; i <= n; i++)
        k = max(k, deg[i]);
    dfs(1, 0);
    vector<vector<ll>> days(k + 1);
    for (ll i = 1; i <= n - 1; i++)
        days[color[i]].push_back(i);
    cout << k << endl;
    for (ll i = 1; i <= k; i++)
    {
        cout << days[i].size() << " ";
        for (auto x : days[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}