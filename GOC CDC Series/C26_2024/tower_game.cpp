#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    bool all = true;
    for (ll i = 0; i < n; i++)
        if (a[i] == 0)
            all = false;
    if (all)
    {
        cout << 0 << endl;
        return;
    }
    vector<ll> ps(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i - 1];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        ans += llabs((i + 1) - ps[i + 1]);
    cout << ans << endl;
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