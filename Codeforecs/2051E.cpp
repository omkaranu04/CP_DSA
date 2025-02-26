#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
pair<ll, ll> func(vector<ll> &a, vector<ll> &b, ll mid, ll n)
{
    ll tot = (lower_bound(b.begin(), b.end(), mid) - b.begin());
    ll non_neg = (lower_bound(a.begin(), a.end(), mid) - a.begin());

    return {non_neg - tot, tot};
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    pair<ll, ll> p;
    for (int i = 0; i < n; i++)
    {
        p = func(a, b, a[i], n);
        if (p.first <= k)
        {
            ans = max(ans, (n - p.second) * a[i]);
        }
        p = func(a, b, b[i], n);
        if (p.first <= k)
        {
            ans = max(ans, (n - p.second) * b[i]);
        }
    }

    // cout << "ans : ";
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