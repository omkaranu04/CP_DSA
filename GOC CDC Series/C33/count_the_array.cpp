#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
void solve()
{
    ll n;
    cin >> n;
    vector<ll> p(n), q(n);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    for (ll i = 0; i < n; i++)
        cin >> q[i];
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    ll j = 0, ans = 1;
    for (ll i = 0; i < n; i++)
    {
        while (j < n && p[j] > q[i])
            j++;
        ll cnt = j - i;
        // cout << j << " " << cnt << " ";
        if (cnt <= 0)
        {
            ans = 0;
            break;
        }
        ans *= cnt;
        ans %= mod;
    }
    // cout << endl;
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