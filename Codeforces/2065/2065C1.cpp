#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m, b;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> b;
    a[0] = min(a[0], b - a[0]);
    for (ll i = 1; i < n; i++)
    {
        ll mini = min(a[i], b - a[i]), maxi = max(a[i], b - a[i]);
        if (maxi < a[i - 1])
        {
            cout << "NO\n";
            return;
        }
        else
        {
            if (mini >= a[i - 1])
                a[i] = mini;
            else
                a[i] = maxi;
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