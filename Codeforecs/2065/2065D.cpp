#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<pair<ll, ll>> sorted_indices;
    for (ll i = 0; i < n; i++)
    {
        ll x = accumulate(a[i].begin(), a[i].end(), 0LL);
        sorted_indices.push_back({x, i});
    }
    sort(sorted_indices.rbegin(), sorted_indices.rend());
    vector<ll> final_array;
    for (ll i = 0; i < n; i++)
    {
        ll index = sorted_indices[i].second;
        for (ll j = 0; j < m; j++)
        {
            final_array.push_back(a[index][j]);
        }
    }
    ll ans = 0, mul = n * m;
    for (auto x : final_array)
    {
        ans += (x * mul);
        mul--;
    }
    cout << ans << endl;
    return;
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