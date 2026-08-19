#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll n;
vector<vector<array<ll, 3>>> g;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    ll totalCost = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        totalCost += c;
        g[a].push_back({b, c, 1});
        g[b].push_back({a, c, 0});
    }
    ll costForward = 0;
    vector<ll> vis(n + 1, 0);
    ll curr = 1, prev = -1;
    vis[curr] = 1;
    for (ll s = 0; s < n; s++)
    {
        ll nxt = -1, cost = -1, dirFlag = -1;
        for (auto &e : g[curr])
        {
            if (e[0] == prev)
                continue;
            nxt = e[0];
            cost = e[1];
            dirFlag = e[2];
        }
        if (!dirFlag)
            costForward += cost;
        prev = curr;
        curr = nxt;
        vis[curr] = 1;
    }
    ll costBackward = totalCost - costForward;
    cout << min(costForward, costBackward) << endl;
    return 0;
}