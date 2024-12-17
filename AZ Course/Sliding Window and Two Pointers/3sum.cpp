#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, target;
    cin >> n >> target;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = LLONG_MAX;
    for (ll i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        ll j = i + 1;
        ll k = n - 1;
        while (j < k)
        {
            ll sum = a[i] + a[j] + a[k];
            ans = min(ans, abs(sum - target));
            if (sum < target)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
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