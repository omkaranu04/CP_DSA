#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1);
    map<ll, ll> mp;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (ll i = 1; i <= n; i++)
        cin >> b[i];
    for (ll i = 1; i <= n; i++)
        cin >> c[i];

    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        ll x = b[c[i]];
        ans += mp[x];
    }
    cout << ans << endl;
    return 0;
}