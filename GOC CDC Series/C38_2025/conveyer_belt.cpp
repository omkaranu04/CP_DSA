#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    bool poss = true;
    for (ll i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            poss = false;
    if (poss)
    {
        cout << 0 << endl;
        return;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (x < a[i])
        {
            swap(x, a[i]);
            ans++;
        }
    }
    poss = true;
    for (ll i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            poss = false;
    if (poss)
        cout << ans << endl;
    else
        cout << -1 << endl;
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