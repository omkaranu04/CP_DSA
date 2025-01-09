#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
ll msb(ll n)
{
    if (n == 0)
        return -1;
    if (n < 0)
        return 63;
    for (ll i = 63; i >= 0; i--)
    {
        if ((n & (1LL << i)) != 0)
        {
            return i;
        }
    }
    return -1;
}
ll lsb(ll n)
{
    if (n == 0)
        return -1;
    for (ll i = 0; i < 64; i++)
    {
        if ((n & (1LL << i)) != 0)
        {
            return i;
        }
    }
    return -1;
}
ll pow2(ll n)
{
    if (n <= 1)
        return 0;
    return (__builtin_popcountll(n) == 1);
}
ll div2(ll n)
{
    if (n == 0)
        return -1;
    return 1LL << (__builtin_ctzll(n));
}
ll small(ll x)
{
    if (x <= 1)
        return 2;
    return (1LL << (64 - __builtin_clzll(x - 1)));
}
void solve()
{
    ll n;
    cin >> n;
    bitset<64> bits(n);
    cout << bits << "\n";
    cout << msb(n) << "\n";
    cout << lsb(n) << "\n";
    cout << pow2(n) << "\n";
    cout << div2(n) << "\n";
    cout << small(n) << "\n";
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