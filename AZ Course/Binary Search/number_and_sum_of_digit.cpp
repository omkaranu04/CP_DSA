#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(ll mid, ll s)
{
    ll copy = mid;
    ll sum = 0;
    while (mid > 0)
    {
        sum += mid % 10;
        mid /= 10;
    }
    return ((copy - sum) >= s);
}
void solve()
{
    ll n, s;
    cin >> n >> s;
    ll low = 1;
    ll high = n;
    ll ans = n + 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (check(mid, s))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << n - ans + 1 << "\n";
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}