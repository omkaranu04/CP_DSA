#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 1000100;
ll a[MAXN], b[MAXN];
void precompute()
{
    a[1] = b[1] = 1;
    for (ll i = 2; i < MAXN; i++)
    {
        a[i] = (2 * 1LL * a[i - 1] + b[i - 1]) % MOD;
        b[i] = (4 * 1LL * b[i - 1] + a[i - 1]) % MOD;
    }
}
void solve()
{
    ll n;
    cin >> n;
    cout << (a[n] + b[n]) % MOD << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    precompute();
    while (t--)
    {
        solve();
    }
    return 0;
}