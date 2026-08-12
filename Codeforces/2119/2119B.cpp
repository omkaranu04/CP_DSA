#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll px, py, qx, qy;
    cin >> px >> py >> qx >> qy;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll mx = *max_element(a.begin(), a.end());
    ll dx = qx - px;
    ll dy = qy - py;
    ll dist2 = dx * dx + dy * dy;
    ll dmax = sum;
    ll dmin = max(0LL, 2 * mx - sum);
    if (dist2 <= dmax * dmax && dist2 >= dmin * dmin)
        cout << "Yes\n";
    else
        cout << "No\n";
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