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
    vector<ll> x(n);
    for (auto &xx : x)
        cin >> xx;
    vector<ll> ps(n, 0);
    ps[0] = x[0];
    for (ll i = 1; i < n; i++)
        ps[i] = ps[i - 1] + x[i];
    ll lmin = 0;
    ll ans = LLONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, ps[i] - lmin);
        lmin = min(lmin, ps[i]);
    }
    cout << ans << endl;
    return 0;
}