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
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    bool ok = false;
    ll x = -1, y = -1;
    for (ll i = 0; i < n && !ok; i++)
    {
        for (ll j = i + 1; j < n && !ok; j++)
        {
            if (a[i] > a[j])
            {
                x = i;
                y = j;
                ok = true;
            }
        }
    }
    if (!ok)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        cout << 2 << endl;
        cout << a[x] << " " << a[y] << endl;
    }
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