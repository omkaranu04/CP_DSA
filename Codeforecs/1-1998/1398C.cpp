#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        a[i] = s[i] - '0';
    vector<ll> ps(n + 1, 0);
    for (ll i = 1; i < n + 1; i++)
        ps[i] = ps[i - 1] + a[i - 1];
    map<ll, ll> mp;
    for (ll i = 0; i < n + 1; i++)
        mp[ps[i] - i]++;
    ll ans = 0;
    for (auto x : mp)
        if (x.second > 0)
            ans += ((x.second) * (x.second - 1)) / 2;
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