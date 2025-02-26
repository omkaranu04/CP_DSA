#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll allQ = (n * (n + 1)) / 2;
    vector<ll> a(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    set<ll> known;
    for (ll i = 0; i < k; i++)
    {
        ll x;
        cin >> x;
        known.insert(x);
    }
    for (ll i = 0; i < m; i++)
    {
        if (known.size() == n || (known.size() == n - 1 && known.count(a[i]) == 0))
            cout << 1;
        else
            cout << 0;
    }
    cout << "\n";
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