#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
vector<vector<ll>> g;
vector<ll> indp, outdp;
void indfs(ll u, ll par)
{
    indp[u] = 0; // treat like a leaf node
    for (ll v : g[u])
    {
        if (v != par)
        {
            indfs(v, u);
            if (indp[v] + 1 > indp[u])
                indp[u] = indp[v] + 1;
        }
    }
}
void outdfs(ll u, ll par, ll outval) // outval is the value passed onto child by parent
{
    outdp[u] = outval;
    ll max1 = -1, max2 = -1;
    // finding for every node max1, and max2 in their children
    for (auto v : g[u])
    {
        if (v != par)
        {
            if (indp[v] > max1)
            {
                max2 = max1;
                max1 = indp[v];
            }
            else if (indp[v] > max2)
                max2 = indp[v];
        }
    }
    for (auto v : g[u])
    {
        if (v != par)
        {
            ll tmp;
            if (indp[v] == max1)
                tmp = max(max2 + 1, outval) + 1;
            else
                tmp = max(max1 + 1, outval) + 1;
            outdfs(v, u, tmp);
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    g.resize(n + 1);
    indp.resize(n + 1, 0);
    outdp.resize(n + 1, 0);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    indfs(1, 0);
    outdfs(1, 0, 0);
    for (ll i = 1; i <= n; i++)
        cout << max(indp[i], outdp[i]) << " ";
    return 0;
}