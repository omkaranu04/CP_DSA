#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    ll sum = 0, ans = 0;
    map<ll, ll> mp;
    mp[0]++;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        sum = (sum + x) % n;
        if (sum < 0)
            sum += n;
        ans += mp[sum];
        mp[sum]++;
    }
    cout << ans << endl;
    return 0;
}