#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll mn = *min_element(a.begin(), a.end());
    ll mx = *max_element(a.begin(), a.end());
    ll diff = mx - mn;

    if (diff > k + 1)
        cout << "Jerry\n";
    else
        cout << (sum % 2 ? "Tom\n" : "Jerry\n");
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