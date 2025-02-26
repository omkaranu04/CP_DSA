#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool countMultiples(ll x, ll l, ll r, ll k)
{
    ll first = (l + x - 1) / x;
    ll last = r / x;
    ll ans = max(0LL, last - first + 1);
    return ans >= k;
}
void solve()
{
    ll l, r, k;
    cin >> l >> r >> k;
    ll ans = 0;
    ll low = l, high = r + 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (countMultiples(mid, l, r, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ((ans - l + 1 > 0) ? ans - l + 1 : 0) << endl;
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