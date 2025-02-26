#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MOD = 1e9 + 7;
ll modpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2)
            res = (res % MOD * a % MOD) % MOD;
        a = (a % MOD * a % MOD) % MOD;
        b /= 2;
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<ll> n(t), k(t);
    for (ll i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (ll i = 0; i < t; i++)
    {
        cin >> k[i];
    }
    for (ll i = 0; i < t; i++)
    {
        cout << modpow(2, k[i]) << endl;
    }

    return 0;
}