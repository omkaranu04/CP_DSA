#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = n / 2 + 1;
    while (r > l + 1)
    {
        ll mid = (l + r) / 2;
        bool ok = true;
        for (ll i = 0; i < mid; i++)
            ok &= (2 * a[i] <= a[n - mid + i]);
        if (ok)
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}