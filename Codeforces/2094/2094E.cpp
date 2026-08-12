#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> cnt(33, 0);
    for (int i = 0; i < 33; i++)
        for (int j = 0; j < n; j++)
            if (a[j] & (1LL << i))
                cnt[i]++;
    ll ans = 0;
    for (int k = 0; k < n; k++)
    {
        ll curr = 0;
        for (ll j = 0; j < 33; j++)
        {
            if (a[k] & (1LL << j))
                curr += (1LL << j) * (n - cnt[j]);
            else
                curr += (1LL << j) * cnt[j];
        }
        ans = max(ans, curr);
    }
    cout << ans << "\n";
    return;
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