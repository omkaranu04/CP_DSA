#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, m;
vector<ll> p, c;
bool check(ll mid)
{
    ll k = (mid + 1) / 2;
    ll j = 0;
    for (ll i = 0; i < m; i++)
    {
        ll cnt = 0;
        while (j < n && p[j] <= c[i] && cnt < k)
        {
            j++;
            cnt++;
        }
    }
    return (j == n);
}
void solve()
{
    p.clear();
    c.clear();

    cin >> n >> m;
    p.resize(n);
    c.resize(m);
    for (ll i = 0; i < n; i++)
        cin >> p[i];
    for (ll i = 0; i < m; i++)
        cin >> c[i];
    sort(p.rbegin(), p.rend());
    sort(c.rbegin(), c.rend());
    if (p[0] > c[0])
    {
        cout << "-1\n";
        return;
    }
    ll lo = 0, hi = 2 * n, ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
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