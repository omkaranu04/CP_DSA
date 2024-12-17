#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for (ll i = 0; i < k; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    vector<ll> xx;
    for (auto [x, y] : mp)
        xx.push_back(y);
    sort(xx.begin(), xx.end());
    ll ans = 0;
    while (n && xx.size())
    {
        ans += xx.back();
        xx.pop_back();
        n--;
    }
    cout << ans << endl;
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