#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    map<ll, ll> freq;
    vector<pair<ll, ll>> prev;
    for (auto x : a)
    {
        map<ll, ll> curr;
        curr[x] += 1;
        for (auto [v, cnt] : prev)
            curr[v | x] += cnt;
        prev.clear();
        prev.reserve(curr.size());
        for (auto &[v, cnt] : curr)
        {
            prev.emplace_back(v, cnt);
            freq[v] += cnt;
        }
    }

    while (q--)
    {
        ll x;
        cin >> x;
        cout << freq[x] << "\n";
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