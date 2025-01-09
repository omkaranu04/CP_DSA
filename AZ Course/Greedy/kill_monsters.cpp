#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first - a.second > b.first - b.second;
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> monsters(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> monsters[i].first >> monsters[i].second;
    }
    sort(monsters.begin(), monsters.end(), cmp);
    ll ans = monsters[0].first;
    for (ll i = 1; i < n; i++)
    {
        ans += monsters[i].first - (monsters[i - 1].first - monsters[i - 1].second);
    }
    cout << ans << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}