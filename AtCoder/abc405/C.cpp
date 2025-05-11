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
    vector<ll> a(n), ps(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * (ps[n] - ps[i + 1]);
    }
    cout << ans << endl;
    return 0;
}