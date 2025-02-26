#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> intervals(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    ll ans = 0, last_finish = INT_MIN;
    for (ll i = 0; i < n; i++)
    {
        if (intervals[i].first > last_finish)
        {
            ans++;
            last_finish = intervals[i].second;
        }
    }
    cout << ans << "\n";
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