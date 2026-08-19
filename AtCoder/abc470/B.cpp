#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll c;
        cin >> c;
        mp[c]++;
    }
    ll maxcol = -1, maxcnt = -1;
    for (auto x : mp)
    {
        if (x.second > maxcnt)
        {
            maxcol = x.first;
            maxcnt = x.second;
        }
    }
    ll ans = 0;
    for (auto x : mp)
    {
        if (x.first != maxcol)
            ans += x.second;
    }
    cout << ans << endl;
    return 0;
}