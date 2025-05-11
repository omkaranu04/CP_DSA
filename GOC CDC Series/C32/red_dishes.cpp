#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
void solve()
{
    ll n;
    cin >> n;
    vector<ll> s(n), ps(n + 1, 0);
    for (ll i = 0; i < n; i++)
        cin >> s[i];
    sort(s.rbegin(), s.rend());
    for (ll i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + s[i - 1];
    ll curr = 0, ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        curr += ps[i];
        ans = max(ans, curr);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}