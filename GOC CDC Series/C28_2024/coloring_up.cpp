#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> freq(n + 1, 0);
    for (ll i = 0; i < k; i++)
    {
        ll u, v;
        cin >> u >> v;
        freq[u]++, freq[v]++;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans += freq[i] * (n - 1 - freq[i]);
    cout << (ans / 2) % mod << endl;
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