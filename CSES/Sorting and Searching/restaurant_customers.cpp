#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> times;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }
    sort(times.begin(), times.end());
    ll ans = 0, cnt = 0;
    for (ll i = 0; i < 2 * n; i++)
    {
        cnt += times[i].second;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}