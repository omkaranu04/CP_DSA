#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
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
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (ll x = 1; x <= n; x++)
    {
        if (a[x - 1] >= x)
            ans = max(ans, x);
        else
            break;
    }
    cout << ans << endl;
    return 0;
}