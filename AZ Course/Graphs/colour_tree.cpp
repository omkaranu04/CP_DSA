#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> g;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    g.resize(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = 0;
    for (auto x : g)
    {
        ans = max(ans, (ll)x.size());
    }
    cout << ans + 1 << endl;
    return 0;
}