#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll check(ll mid, vector<ll> &a) // return cnt of subarrays with sum<=mid
{
    ll curr = 0, start = 0, currsum = 0, ans = 0;
    while (curr < a.size())
    {
        currsum += a[curr];
        while (start <= curr && currsum > mid)
        {
            currsum -= a[start];
            start++;
        }
        ans += (curr - start + 1);
        curr++;
    }
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll lo = *min_element(a.begin(), a.end());
    ll hi = accumulate(a.begin(), a.end(), 0LL), ans = -1;
    ll m = (n * (n + 1)) / 2;
    m = (m + 1) / 2;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid, a) >= m)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
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