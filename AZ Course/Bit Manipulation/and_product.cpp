#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll noOf1sFrom0(ll x, ll i)
{
    ll tot = x + 1;
    ll cyc = (1LL << (i + 1));
    ll tot_cyc = tot / cyc;
    ll rem = tot % cyc;
    ll rem1s = max(0LL, rem - (1LL << i));
    ll ans = tot_cyc * (1LL << i) + rem1s;
    return ans;
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<ll> ans;
    for (ll i = 0; i < n; i++)
    {
        ll l = a[i], r = b[i];
        ll tmp = 0;
        for (ll j = 0; j < 32; j++)
        {
            ll no1s = noOf1sFrom0(r, j) - noOf1sFrom0(l - 1, j);
            if (no1s == (r - l + 1))
                tmp += (1LL << j);
        }
        ans.push_back(tmp);
    }
    for (auto x : ans)
        cout << x << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}