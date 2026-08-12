#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    set<ll> ps;
    ll ans = 0;
    for (ll i = 0; i < n + 1; i++)
    {
        if (ps.count(a[i]))
        {
            ans++;
            ps.clear();
        }
        ps.insert(a[i]);
    }
    cout << ans << "\n";
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