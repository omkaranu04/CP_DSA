#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, c;
vector<ll> a, b;
bool check(ll mid)
{
    ll cnt = 0;
    for (ll i = 0; i < c; i++)
        if (a[i] >= b[mid - 1])
            cnt++;
    if (cnt > c - cnt)
        return true;
    for (ll i = c; i < n; i++)
    {
        if (a[i] >= b[mid - 1])
            cnt++;
        if (a[i - c] >= b[mid - 1])
            cnt--;
        if (cnt > c - cnt)
            return true;
    }
    return false;
}
void solve()
{
    a.clear();
    b.clear();

    cin >> n >> c;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    sort(b.rbegin(), b.rend()); // b is sorted
    ll lo = 1, hi = n, ans = n;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;
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