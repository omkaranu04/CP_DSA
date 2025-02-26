#include <bits/stdc++.h>
using namespace std;
#define ll long long int
pair<ll, ll> cal(ll k, ll mid, ll n)
{
    ll v1 = (mid + k - 1 + k) * mid / 2;
    ll v2 = ((k + n - 1 + k) * n / 2) - v1;
    return {v1, v2};
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll l = 0, r = n, ans = 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        auto [a, b] = cal(k, mid, n);
        if (b > a)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    auto [a1, b1] = cal(k, ans, n);
    auto [a2, b2] = cal(k, ans + 1, n);
    if (abs(a1 - b1) > abs(a2 - b2))
        cout << abs(a2 - b2) << endl;
    else
        cout << abs(a1 - b1) << endl;
    return;
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