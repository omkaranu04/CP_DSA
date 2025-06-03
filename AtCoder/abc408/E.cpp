#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m, token;
vector<vector<pair<ll, ll>>> g;
vector<ll> vis;
bool canreach(ll mask)
{
    queue<ll> q;
    q.push(1);
    vis[1] = token;
    while (!q.empty())
    {
        ll u = q.front();
        ;
        q.pop();
        if (u == n)
            return true;
        for (auto &[v, w] : g[u])
        {
            if (vis[v] != token && (w & mask) == 0)
            {
                vis[v] = token;
                q.push(v);
            }
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ll ans = 0, forbid = 0;
    token = 1;

    for (ll bit = 31; bit >= 0; bit--)
    {
        ll tforbid = forbid | (1LL << bit);
        token++;
        if (canreach(tforbid))
            forbid = tforbid;
        else
            ans |= (1LL << bit);
    }

    cout << ans << endl;

    return 0;
}