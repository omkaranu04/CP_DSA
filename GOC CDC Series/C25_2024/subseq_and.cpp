#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> cnt(32, 0);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j <= 31; j++)
        {
            if (a[i] & (1LL << j))
                cnt[j]++;
        }
    }
    ll ans = 1;
    for (ll i = 0; i < 32; i++)
        ans = max(ans, cnt[i]);
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