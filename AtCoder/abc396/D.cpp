#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, m;
vector<vector<pair<ll, ll>>> g;
ll ans = (1LL << 60);
void rec(ll node, ll val, ll mask)
{
    if (node == n)
    {
        ans = min(ans, val);
        return;
    }
    for (auto x : g[node])
    {
        ll v = x.first;
        ll w = x.second;

        if (mask & (1LL << (v - 1)))
            continue;

        rec(v, val ^ w, (mask | (1LL << (v - 1))));
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    g.resize(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    rec(1, 0, 1);
    cout << ans << endl;
    return 0;
}