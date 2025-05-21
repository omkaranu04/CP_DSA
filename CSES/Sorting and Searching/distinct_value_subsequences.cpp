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
    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
        mp[x[i]]++;
    ll ans = 1;
    for (auto x : mp)
        ans = (ans % mod * (x.second + 1) % mod) % mod;
    cout << (ans - 1 + mod) % mod << endl;
    return 0;
}