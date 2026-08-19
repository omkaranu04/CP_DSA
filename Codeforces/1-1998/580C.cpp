#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<vector<ll>> g;
vector<ll> isCat;

ll dfs(ll node, ll parent, ll consec)
{
    ll newConsec = isCat[node] ? consec + 1 : 0;
    if (newConsec > m)
        return 0;
    bool isLeaf = (g[node].size() == 1 && node != 1);
    if (isLeaf)
        return 1;

    ll count = 0;
    for (auto v : g[node])
    {
        if (v != parent)
            count += dfs(v, node, newConsec);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    isCat.resize(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> isCat[i];
    for (ll i = 1; i <= n - 1; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout << dfs(1, 0, 0) << endl;
    return 0;
}