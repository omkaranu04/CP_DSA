#include <bits/stdc++.h>
using namespace std;
#define ll double
ll dist(pair<ll, ll> a, pair<ll, ll> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }
    ll ans = dist({0, 0}, points[0]);
    for (int i = 1; i < n; i++)
    {
        ans += dist(points[i - 1], points[i]);
    }
    ans += dist(points[n - 1], {0, 0});
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}