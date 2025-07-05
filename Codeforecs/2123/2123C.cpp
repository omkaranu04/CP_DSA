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
    vector<ll> pref(n), suff(n);
    pref[0] = a[0];
    for (ll i = 1; i < n; i++)
        pref[i] = ((a[i] < pref[i - 1]) ? a[i] : pref[i - 1]);
    suff[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--)
        suff[i] = ((a[i] > suff[i + 1]) ? a[i] : suff[i + 1]);
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        cout << (((pref[i] == a[i]) || suff[i] == a[i]) ? '1' : '0');
    cout << endl;
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