#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (ll i = 31; i >= 0; i--)
    {
        vector<ll> temp;
        for (auto v : a)
        {
            if (v & (1LL << i))
            {
                temp.push_back(v);
            }
        }
        if (temp.size() >= x)
        {
            a = temp;
            ans += (1LL << i);
        }
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