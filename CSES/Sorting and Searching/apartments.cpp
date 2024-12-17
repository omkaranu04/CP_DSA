#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll i = 0, j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (b[j] >= a[i] - k && b[j] <= a[i] + k)
        {
            i++;
            j++;
            ans++;
        }
        else if (b[j] < a[i] - k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}