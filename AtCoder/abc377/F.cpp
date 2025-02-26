#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    set<ll> rows, cols, diags, anti_diags;
    for (ll i = 1; i <= m; i++)
    {
        ll a, b;
        cin >> a >> b;
        rows.insert(a);
        cols.insert(b);
        diags.insert(a + b);
        anti_diags.insert(a - b);
    }
    ll ans = (n - rows.size()) * (n - cols.size());

    for (ll d : diags)
    {
        set<ll> exes;
        for (ll x : rows)
        {
            if (d - x >= 1 && d - x <= n)
                exes.insert(x);
        }
        for (ll y : cols)
        {
            if (d - y >= 1 && d - y <= n)
                exes.insert(d - y);
        }
        ans -= (2 * min(d, n + 1) - d - 1) - exes.size();
    }
    for (ll d : anti_diags)
    {
        set<ll> exes;
        for (ll x : rows)
        {
            if (x - d >= 1 && x - d <= n)
                exes.insert(x);
        }
        for (ll y : cols)
        {
            if (y + d >= 1 && y + d <= n)
                exes.insert(y + d);
        }
        for (ll e : diags)
        {
            if ((d + e) % 2 == 0 && 1 <= (d + e) / 2 && (d + e) / 2 <= n && 1 <= (e - d) / 2 && (e - d) / 2 <= n)
                exes.insert((d + e) / 2);
        }
        ans -= n - min(d, -d);
        ans += exes.size();
    }
    cout << ans << endl;
    return 0;
}