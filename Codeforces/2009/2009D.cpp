#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    set<pair<ll, ll>> pts;
    unordered_map<ll, ll> xs;
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
        xs[points[i].first]++;
        pts.insert(points[i]);
    }
    ll ans = 0;
    for (auto i : xs)
    {
        if (i.second == 2)
            ans += n - 2;
    }
    for (auto i : pts)
    {
        if (pts.count({i.first - 1, i.second ^ 1}) && pts.count({i.first + 1, i.second ^ 1}))
            ans++;
    }
    cout << ans << endl;
}

int main()
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
