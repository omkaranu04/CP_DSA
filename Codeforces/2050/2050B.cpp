#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll esum = 0, osum = 0;
    ll e = 0, o = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i % 2)
        {
            osum += a[i];
            o++;
        }
        else
        {
            esum += a[i];
            e++;
        }
    }
    if ((osum % o == 0) && (esum % e == 0) && (osum / o == esum / e))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
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