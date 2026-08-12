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
    bool poss = false;
    for (ll i = 1; i < n; i++)
    {
        if (abs(a[i - 1] - a[i]) <= 1)
        {
            poss = true;
            break;
        }
    }
    if (poss)
    {
        cout << "0\n";
        return;
    }
    poss = false;
    for (ll i = 0; i + 1 < n; i++)
    {
        ll lo = min(a[i], a[i + 1]);
        ll hi = max(a[i], a[i + 1]);
        if (i - 1 >= 0)
        {
            if (max(lo, a[i - 1] - 1) <= min(hi, a[i - 1] + 1))
            {
                poss = true;
                break;
            }
        }
        if (i + 2 < n)
        {
            if (max(lo, a[i + 2] - 1) <= min(hi, a[i + 2] + 1))
            {
                poss = true;
                break;
            }
        }
    }
    if (poss)
    {
        cout << "1\n";
        return;
    }
    vector<ll> pmin(n), pmax(n), smin(n), smax(n);
    pmin[0] = a[0];
    pmax[0] = a[0];
    smin[n - 1] = a[n - 1];
    smax[n - 1] = a[n - 1];
    for (ll i = 1; i < n; i++)
    {
        pmin[i] = min(pmin[i - 1], a[i]);
        pmax[i] = max(pmax[i - 1], a[i]);
    }
    for (ll i = n - 2; i >= 0; i--)
    {
        smin[i] = min(smin[i + 1], a[i]);
        smax[i] = max(smax[i + 1], a[i]);
    }
    poss = false;
    for (ll k = 0; k + 1 < n; k++)
    {
        ll lmin = pmin[k], lmax = pmax[k];
        ll rmin = smin[k + 1], rmax = smax[k + 1];
        if (max(lmin, rmin) - min(lmax, rmax) <= 1)
        {
            poss = true;
            break;
        }
    }
    if (poss)
    {
        cout << n - 2 << endl;
        return;
    }
    cout << -1 << endl;
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