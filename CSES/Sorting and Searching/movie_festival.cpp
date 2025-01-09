#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), comp);
    ll ans = 0, last = 0;
    for (ll i = 0; i < n; i++)
    {
        if (v[i].first >= last)
        {
            ans++;
            last = v[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}