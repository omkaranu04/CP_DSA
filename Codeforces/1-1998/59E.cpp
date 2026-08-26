#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n, m, k;
vector<vector<ll>> g;
map<pair<ll, ll>, set<ll>> mp;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    g.resize(n + 1);
    for (ll i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (ll i = 1; i <= k; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        mp[{a, b}].insert(c);
    }

    // Double-state BFS
    vector<vector<ll>> par(n + 1, vector<ll>(n + 1, -2));
    queue<pair<ll, ll>> q;
    par[0][1] = -1;
    q.push({0, 1});
    ll lastPrev = -1;
    while (!q.empty())
    {
        auto [prev, u] = q.front();
        q.pop();
        if (u == n)
        {
            lastPrev = prev;
            break;
        }
        for (auto v : g[u])
        {
            if (prev != 0 && mp[{prev, u}].count(v))
                continue;
            if (par[u][v] != -2)
                continue;
            par[u][v] = prev;
            q.push({u, v});
        }
    }
    if (lastPrev == -1)
    {
        cout << "-1\n";
        return 0;
    }
    vector<ll> ans;
    ll curr = n, prev = lastPrev;
    while (curr != 1)
    {
        ans.push_back(curr);
        ll bPrev = par[prev][curr];
        curr = prev;
        prev = bPrev;
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    cout << ans.size() - 1 << endl;
    for (auto x : ans)
        cout << x << " ";
    return 0;
}