#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<pair<ll, ll>> v;
    for (auto i : mp)
    {
        v.push_back({i.second, i.first});
    }
    ll distinct = v.size();
    sort(v.begin(), v.end());
    for (auto &p : v)
    {
        if (k >= p.first)
        {
            k -= p.first;
            distinct--;
        }
        else
            break;
    }
    // cout << "ans : ";
    cout << max(1LL, distinct) << endl;
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