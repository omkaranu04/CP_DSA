#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    k--;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> x(n, 0);
    for (ll i = 0; i < n; i++)
    {
        if (a[i] > a[k])
            x[i] = 1;
        if (a[i] < a[k])
            x[i] = -1;
    }
    map<ll, ll> mp;
    ll ans = 0, curr = 0;
    mp[0] = 1;
    for (ll i = 0; i < k; i++)
    {
        curr += x[i];
        mp[curr]++;
    }
    for (ll i = k; i < n; i++)
    {
        curr += x[i];
        if (mp.find(curr) != mp.end())
            ans += mp[curr];
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