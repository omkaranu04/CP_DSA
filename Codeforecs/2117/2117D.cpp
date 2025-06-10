#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }
    ll num = 2 * a[1] - a[2];
    ll den = n + 1;
    if (num < 0 || num % den != 0)
    {
        cout << "NO\n";
        return;
    }
    ll y = num / den;
    ll x = a[1] - n * y;
    if (x < 0)
    {
        cout << "NO\n";
        return;
    }
    for (ll i = 1; i <= n; i++)
    {
        ll tmp = i * x + (n - i + 1) * y;
        if (tmp != a[i])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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