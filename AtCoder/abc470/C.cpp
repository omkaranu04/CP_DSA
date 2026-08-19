#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n, 0);
    set<ll> active;
    ll ans = 0;
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x;
            cin >> x;
            x--;
            ans ^= a[x];
            a[x]++;
            ans ^= a[x];
            if (a[x] == 1)
                active.insert(x);
        }
        if (type == 2)
        {
            for (auto it = active.begin(); it != active.end();)
            {
                ll x = *it;
                ans ^= a[x];
                a[x] -= 1;
                ans ^= a[x];
                if (a[x] == 0)
                    it = active.erase(it);
                else
                    it++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}