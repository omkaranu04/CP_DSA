#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> jobs(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> jobs[i].first;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> jobs[i].second;
    }
    sort(jobs.begin(), jobs.end());
    ll ans = 0, curr_time = 0;
    for (ll i = 0; i < n; i++)
    {
        if (jobs[i].first >= curr_time + jobs[i].second)
        {
            ans++;
            curr_time += jobs[i].second;
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