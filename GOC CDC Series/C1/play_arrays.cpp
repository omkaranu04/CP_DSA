#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0, mini = 1e9;
    for (ll i = 0; i < n; i++)
    {
        ans = max(ans, a[i] - mini);
        mini = min(mini, a[i]);
    }
    cout << ans << endl;
}