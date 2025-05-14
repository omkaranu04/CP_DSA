#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    vector<ll> a(5);
    for (ll i = 0; i < 5; i++)
        cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    if (sum >= 35)
    {
        cout << "0\n";
        return;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < 5; i++)
    {
        sum += (10 - a[i]);
        ans += 100;
        if (sum >= 35)
            break;
    }
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