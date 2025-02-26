#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> ps(2 * n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + a[i - 1];
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        ps[i] = ps[i - 1] + a[i - n - 1];
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        int block1 = l / n, block2 = r / n;
        l = l % n;
        r = r % n;
        ll ans = 0;
        ans += (block2 - block1 + 1) * ps[n];
        ans -= ps[block1 + l] - ps[block1];
        ans -= ps[block2 + n] - ps[block2 + r + 1];
        cout << ans << endl;
    }
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