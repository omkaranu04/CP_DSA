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
    string s;
    cin >> s;
    ll mul = 1, rem = 0, ans = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for (ll i = s.length() - 1; i >= 0; i--)
    {
        ll dig = s[i] - '0';
        rem = (rem + dig * mul) % 2019;
        ans += mp[rem];
        mp[rem]++;
        mul = (mul * 10) % 2019;
    }
    cout << ans << endl;
    return 0;
}