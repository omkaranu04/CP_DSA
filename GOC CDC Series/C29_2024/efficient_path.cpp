#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, m, k;
vector<vector<pair<ll, ll>>> g;
bool bfs(ll mid)
{
    vector<ll> dist(n + 1, -1);
    queue<ll> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        ll d = dist[u];
        if (d >= k)
            break;

        for (auto &[v, w] : g[u])
        {
            if (dist[v] == -1 && w <= mid)
            {
                if (v == n && d + 1 <= k)
                    return true;
                q.push(v);
                dist[v] = d + 1;
            }
        }
    }
    return false;
}
void solve()
{
    g.clear();

    cin >> n >> m >> k;
    g.resize(n + 1);
    ll lo = 0, hi = 0, ans = -1;
    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        hi = max(hi, w);
    }

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (bfs(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
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
        solve();
    }
    return 0;
}