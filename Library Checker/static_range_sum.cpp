#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), ps(n + 1, 0);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 1; i < n + 1; i++)
        ps[i] = ps[i - 1] + a[i - 1];
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << ps[r] - ps[l] << endl;
    }
    return 0;
}