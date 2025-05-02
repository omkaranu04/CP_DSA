#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    map<ll, ll> mp;
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[(a + b) % n]++;
    }
    ll ans = (m * 1LL * (m - 1)) / 2;
    for (auto it : mp)
    {
        ans -= (it.second * 1LL * (it.second - 1)) / 2;
    }
    cout << ans << endl;
    return 0;
}