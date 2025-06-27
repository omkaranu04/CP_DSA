#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll MAXC = 10;
const ll MAXN = 100;
ll ps[MAXC + 1][MAXN + 1][MAXN + 1];
ll sum(ll s, ll x1, ll y1, ll x2, ll y2)
{
    return ps[s][x2][y2] - ps[s][x1 - 1][y2] - ps[s][x2][y1 - 1] + ps[s][x1 - 1][y1 - 1];
}
void solve()
{
    ll n, q, c;
    cin >> n >> q >> c;

    memset(ps, 0, sizeof(ps));
    for (ll i = 0; i < n; i++)
    {
        ll x, y, s;
        cin >> x >> y >> s;
        ps[s][x][y]++;
    }

    for (ll s = 0; s <= c; s++)
    {
        for (ll x = 1; x <= MAXN; x++)
        {
            for (ll y = 1; y <= MAXN; y++)
            {
                ps[s][x][y] += ps[s][x - 1][y] + ps[s][x][y - 1] - ps[s][x - 1][y - 1];
            }
        }
    }

    while (q--)
    {
        ll t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll ans = 0;
        for (ll s = 0; s <= c; s++)
        {
            ll cnt = sum(s, x1, y1, x2, y2);
            ans += cnt * 1LL * ((s + t) % (c + 1));
        }
        cout << ans << endl;
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