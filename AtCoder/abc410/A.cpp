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
    ll n, k;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    cin >> k;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (k <= a[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}