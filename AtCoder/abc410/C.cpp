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
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        a[i] = i + 1;
    ll offset = 0;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll p, x;
            cin >> p >> x;
            ll idx = (p - 1 + offset) % n;
            a[idx] = x;
        }
        else if (t == 2)
        {
            ll p;
            cin >> p;
            ll idx = (p - 1 + offset) % n;
            cout << a[idx] << endl;
        }
        else
        {
            ll k;
            cin >> k;
            offset += k;
            offset %= n;
        }
    }
    return 0;
}