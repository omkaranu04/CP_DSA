#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    multiset<ll> ss;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ss.insert(x);
    }
    while (ss.size() > 1)
    {
        auto it = ss.begin();
        ll a = *it;
        ss.erase(it);
        it = ss.begin();
        ll b = *it;
        ss.erase(it);
        ss.insert(a + b - 1);
    }
    auto it = ss.begin();
    ll ans = *it;
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