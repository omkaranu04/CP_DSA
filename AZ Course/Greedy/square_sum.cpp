#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll sum1 = sum / n;
    ll sum2 = sum1;
    if (sum % n != 0)
    {
        sum2++;
    }
    ll ans1 = 0, ans2 = 0;
    for (ll i = 0; i < n; i++)
    {
        ans1 += pow(a[i] - sum1, 2);
        ans2 += pow(a[i] - sum2, 2);
    }
    cout << min(ans1, ans2) << "\n";
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