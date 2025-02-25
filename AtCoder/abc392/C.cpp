#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> p(n + 1), q(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    unordered_map<ll, ll> mp;
    for (ll i = 1; i <= n; i++)
    {
        mp[q[i]] = i;
    }
    for (ll i = 1; i <= n; i++)
    {
        ll px = mp[i];
        ll s = p[px];
        cout << q[s] << " ";
    }
    return 0;
}