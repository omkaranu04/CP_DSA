#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> count_of_1s(64, 0);
    for (ll i = 0; i < 22; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if (a[j] & (1LL << i))
            {
                count_of_1s[i]++;
            }
        }
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ll num_gen = 0;
        for (ll j = 0; j < 22; j++)
        {
            if (count_of_1s[j])
            {
                num_gen |= (1LL << j);
                count_of_1s[j]--;
            }
        }
        ans += num_gen * num_gen;
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