#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> x(n);
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        x.push_back({a, 1});
        x.push_back({b, -1});
    }
    sort(x.begin(), x.end());
    ll ans = 0, cnt = 0;
    for (auto p : x)
    {
        cnt += p.second;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}