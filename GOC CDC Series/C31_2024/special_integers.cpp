#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll sum(ll x)
{
    ll ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res = res * res;
    if (b % 2)
        return res * a;
    else
        return res;
}
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    set<ll> ans;
    for (ll fx = 0; fx <= 90; fx++)
    {
        ll x = b * 1LL * binpow(fx, a) + c;
        if (x < 0 || x > 1e9)
            continue;
        if (sum(x) == fx)
            ans.insert(x);
    }
    if (ans.empty())
        cout << "-1\n";
    else
    {
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
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