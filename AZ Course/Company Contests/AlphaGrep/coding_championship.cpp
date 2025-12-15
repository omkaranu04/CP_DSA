#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAX_BITS = 60;
ll pow2[MAX_BITS];
void precomp()
{
    pow2[0] = 1;
    for (ll i = 1; i < MAX_BITS; i++)
        pow2[i] = (pow2[i - 1] * 1LL * 2) % MOD;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> cnt1(MAX_BITS, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll b = 0; b < MAX_BITS; b++)
        {
            if (a[i] & (1LL << b))
                cnt1[b]++;
        }
    }
    ll ans = 0;
    for (ll b = 0; b < MAX_BITS; b++)
    {
        ll cnt0 = n - cnt1[b];
        ll tmp = (cnt1[b] * cnt0) % MOD;
        tmp = (tmp * pow2[b]) % MOD;
        ans = (ans + tmp) % MOD;
    }
    cout << ans % MOD << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precomp();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}