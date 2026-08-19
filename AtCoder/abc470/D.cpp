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
    vector<ll> p(n + 1), inv(n + 1);
    ll ifa = 1;
    for (ll i = 1; i <= n; i++)
    {
        cin >> p[i];
        inv[p[i]] = i;
    }
    while (q--)
    {
        ll type;
        cin >> type;
        if (type == 1)
        {
            ll x, y;
            cin >> x >> y;
            if (ifa)
            {
                ll tx = p[x], ty = p[y];
                swap(p[x], p[y]);
                swap(inv[tx], inv[ty]);
            }
            else
            {
                ll tx = inv[x], ty = inv[y];
                swap(inv[x], inv[y]);
                swap(p[tx], p[ty]);
            }
        }
        else
        {
            ifa ^= 1;
        }
    }
    vector<ll> ans(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        if (ifa)
            cout << p[i] << " ";
        else
            cout << inv[i] << " ";
    }
    cout << endl;
    return 0;
}