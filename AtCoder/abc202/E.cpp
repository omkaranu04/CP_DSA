#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, timer, q;
vector<vector<ll>> g, depth;
vector<ll> intime, outtime, euler_tour;

void dfs(ll u, ll par, ll dep)
{
    intime[u] = timer;
    depth[dep].push_back(intime[u]);
    timer++;

    for (auto v : g[u])
    {
        if (v != par)
        {
            dfs(v, u, dep + 1);
        }
    }

    outtime[u] = timer;
    timer++;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    depth.resize(n + 1);
    intime.resize(n + 1);
    outtime.resize(n + 1);

    // given parents store in the graph
    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    timer = 0;
    dfs(1, 0, 0);

    for (ll i = 0; i <= n; i++)
        sort(depth[i].begin(), depth[i].end());

    // for (ll i = 0; i <= n; i++)
    // {
    //     if (!depth[i].empty())
    //     {
    //         cout << i << " : ";
    //         for (auto x : depth[i])
    //             cout << x << " ";
    //     }
    //     cout << endl;
    // }

    cin >> q;
    while (q--)
    {
        ll u, d;
        cin >> u >> d;

        if (d >= depth.size() || depth[d].empty())
        {
            cout << 0 << endl;
            continue;
        }

        auto left = lower_bound(depth[d].begin(), depth[d].end(), intime[u]);
        auto right = lower_bound(depth[d].begin(), depth[d].end(), outtime[u]);
        cout << right - left << endl;
    }
    return 0;
}