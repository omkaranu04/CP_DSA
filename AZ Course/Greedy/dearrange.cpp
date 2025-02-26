#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll max_occur = 0;
    for (auto i : mp)
    {
        max_occur = max(max_occur, i.second);
    }
    if (max_occur >= (n - max_occur))
    {
        cout << 2 * (n - max_occur) << "\n";
    }
    else
    {
        cout << n << "\n";
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}