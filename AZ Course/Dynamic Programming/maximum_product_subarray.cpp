#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
void solve()
{
    ll n;
    vector<ll> nums;
    cin >> n;
    nums.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    ll mini = 1, maxi = 1;
    ll ans = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        ll temp = mini;
        mini = min({nums[i], mini * nums[i], maxi * nums[i]});
        maxi = max({nums[i], temp * nums[i], maxi * nums[i]});
        ans = max(ans, maxi);
    }
    cout << ans << endl;
    return;
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