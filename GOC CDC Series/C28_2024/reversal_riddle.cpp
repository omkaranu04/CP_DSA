#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    map<ll, ll> mp;
    ll ans = 1;
    for (ll i = 1; i <= n; i++)
    {
        ans += (i - 1 - mp[a[i]]);
        mp[a[i]]++;
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