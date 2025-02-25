#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin >> n >> m;
    ll ans = 0;

    vector<unordered_set<ll>> adj(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        if (u == v)
        {
            ans++;
            continue;
        }
        if (adj[u].count(v))
        {
            ans++;
        }
        else
        {
            adj[u].insert(v);
            adj[v].insert(u);
        }
    }

    cout << ans << endl;
    return 0;
}
