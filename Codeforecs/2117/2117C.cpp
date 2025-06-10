#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    unordered_set<ll> s;
    vector<ll> dist(n);
    for (ll i = 0; i < n; i++)
    {
        s.insert(a[i]);
        dist[i] = s.size();
    }
    ll ans = 0;
    ll start = n - 1, end = n - 1;
    while (end >= 0)
    {
        ll expected_dist = dist[start];
        set<ll> tmp;
        while (end >= 0 && tmp.size() < expected_dist)
        {
            tmp.insert(a[end]);
            end--;
        }
        ans++;
        start = end;
    }
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