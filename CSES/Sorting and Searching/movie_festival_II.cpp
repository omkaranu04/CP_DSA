#include <bits/stdc++.h>
using namespace std;
#define ll int
#define endl "\n"
const ll mod = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end()); // sort by end times
    ll ans = 0;
    multiset<ll> ends;
    for (ll i = 0; i < k; i++)
        ends.insert(0LL);
    for (ll i = 0; i < n; i++)
    {
        ll start = a[i].second, end = a[i].first;
        auto it = ends.upper_bound(start);
        if (it == ends.begin())
            continue;
        --it;
        ends.erase(it);
        ends.insert(end);
        ++ans;
    }
    cout << ans;
    return 0;
}