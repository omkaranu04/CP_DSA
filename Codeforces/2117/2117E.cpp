#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    if (a[n - 1] == b[n - 1])
    {
        cout << n << endl;
        return;
    }
    ll ans = -1;
    vector<ll> seen(n + 1, 0);
    for (ll i = n - 2; i >= 0; i--)
    {
        if (a[i] == b[i] || a[i] == a[i + 1] || b[i] == b[i + 1] || seen[a[i]] || seen[b[i]])
        {
            ans = i;
            break;
        }
        seen[a[i + 1]] = 1;
        seen[b[i + 1]] = 1;
    }
    cout << ans + 1 << endl;
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