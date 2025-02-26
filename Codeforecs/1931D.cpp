#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<pair<int, int>, int> hash;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto tmp = hash.find({((x - (a[i]) % x) % x), a[i] % y});
        if (tmp != hash.end())
            ans += tmp->second;
        hash[{a[i] % x, a[i] % y}]++;
    }
    cout << ans << endl;
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