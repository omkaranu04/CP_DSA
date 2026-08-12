#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    if (k >= 3)
        cout << 0 << endl;
    else
    {
        sort(a.begin(), a.end());
        ll ans = a[0];
        if (k == 1)
        {
            for (ll i = 1; i < n; i++)
                ans = min(ans, a[i] - a[i - 1]);
            cout << ans << endl;
        }
        else
        {
            for (ll i = 0; i < n; i++)
            {
                for (ll j = 0; j < i; j++)
                {
                    ll d = a[i] - a[j];
                    ans = min(ans, d);
                    int x = lower_bound(a.begin(), a.end(), d) - a.begin();
                    if (x < n)
                        ans = min(ans, llabs(a[x] - d));
                    if (x - 1 >= 0)
                        ans = min(ans, llabs(a[x - 1] - d));
                    if (x + 1 < n)
                        ans = min(ans, llabs(a[x + 1] - d));
                }
            }
            cout << ans << endl;
        }
    }
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