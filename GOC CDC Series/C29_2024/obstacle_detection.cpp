#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll q;
    cin >> q;
    multiset<ll> obs;
    while (q--)
    {
        ll t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            obs.insert(x);
        }
        if (t == 2)
        {
            ll l, size;
            cin >> l >> size;
            auto it = obs.lower_bound(l);
            if (it != obs.end() && *it <= (l + size))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
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