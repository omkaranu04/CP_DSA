#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n), w(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += v[i] * w[i];
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