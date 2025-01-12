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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        auto it = lower_bound(a.begin(), a.end(), 2 * a[i]);
        if (it == a.end())
            continue;
        else
        {
            ll idx = it - a.begin();
            ans += (n - idx);
            // cout << idx << endl;
        }
    }
    cout << ans << endl;
    return 0;
}