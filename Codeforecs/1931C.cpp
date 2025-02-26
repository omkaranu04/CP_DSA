#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll i1 = 0, i2 = 0;
    while (a[i1] == a[0] && i1 < n)
        i1++;
    while (a[n - i2 - 1] == a[n - 1] && i2 < n)
        i2++;

    ll ans = n;
    if (a[0] == a[n - 1])
    {
        ans -= i1;
        ans -= i2;
    }
    else
    {
        ans -= max(i1, i2);
    }
    cout << max(0ll, ans) << endl;
    return;
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