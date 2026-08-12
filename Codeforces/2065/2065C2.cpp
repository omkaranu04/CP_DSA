#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (ll i = 0; i < m; i++)
    {
        a[0] = min(a[0], b[i] - a[0]);
    }
    for (ll i = 1; i < n; i++)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]);
        if (it != b.end())
        {
            if (a[i] < a[i - 1])
                a[i] = *it - a[i];
            else
                a[i] = min(a[i], *it - a[i]);
        }
        if (a[i] < a[i - 1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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