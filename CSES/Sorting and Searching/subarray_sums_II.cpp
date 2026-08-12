#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, x;
    cin >> n >> x;
    ll sum = 0, ans = 0;
    map<ll, ll> mp;
    mp[0]++;
    for (ll i = 0; i < n; i++)
    {
        ll xx;
        cin >> xx;
        sum = sum + xx;
        ans += mp[sum - x];
        mp[sum]++;
    }
    cout << ans << endl;
    return 0;
}