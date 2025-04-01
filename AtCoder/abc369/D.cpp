#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll even = 0, odd = -1e18;
    for (ll i = 0; i < n; i++)
    {
        ll eventt = even;
        even = max(even, odd + 2 * a[i]);
        odd = max(odd, eventt + a[i]);
    }
    cout << max(even, odd) << endl;
    return 0;
}