#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<ll>> g(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    string ans = string(n + 1, '0');
    for (ll u = 1; u <= n; u++)
    {
        map<ll, ll> mp;
        for (auto v : g[u])
        {
            mp[a[v]]++;
        }
        mp[a[u]]++;
        for (auto [a, b] : mp)
        {
            if (b >= 2)
                ans[a] = '1';
        }
    }
    for (ll i = 1; i <= n; i++)
        cout << ans[i];
    cout << '\n';
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