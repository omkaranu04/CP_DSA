#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, d;
    cin >> n >> d;
    vector<ll> t(n), l(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> t[i] >> l[i];
    }
    for (ll i = 1; i <= d; i++)
    {
        ll ans = -1;
        for (ll j = 0; j < n; j++)
        {
            ans = max(ans, (t[j]) * (l[j] + i));
        }
        cout << ans << endl;
    }
    return 0;
}