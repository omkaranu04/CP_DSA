#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;

ll n, m;
vector<ll> pref, suff, sum, mx, dp;

void solve()
{
    pref.clear();
    suff.clear();
    sum.clear();
    mx.clear();
    dp.clear();

    cin >> n >> m;
    pref.resize(n + 1);
    suff.resize(n + 1);
    sum.resize(n + 1);
    mx.resize(n + 1);
    dp.resize(m + 1);

    for (ll i = 1; i <= n; i++)
    {
        ll sz;
        cin >> sz;
        vector<ll> a(sz);

        // Total sum
        for (ll j = 0; j < sz; j++)
        {
            cin >> a[j];
            sum[i] += a[j];
        }

        // Max subarray sum (Kadane's algorithm)
        ll max_sub = LLONG_MIN, current = 0;
        for (ll j = 0; j < sz; j++)
        {
            current = max(current + a[j], a[j]);
            max_sub = max(max_sub, current);
        }
        mx[i] = max_sub;

        // Suffix max
        current = 0;
        ll suffix_max = LLONG_MIN;
        for (ll j = sz - 1; j >= 0; j--)
        {
            current += a[j];
            suffix_max = max(suffix_max, current);
        }
        suff[i] = suffix_max;

        // Prefix max
        current = 0;
        ll prefix_max = LLONG_MIN;
        for (ll j = 0; j < sz; j++)
        {
            current += a[j];
            prefix_max = max(prefix_max, current);
        }
        pref[i] = prefix_max;
    }

    ll ans = LLONG_MIN;

    for (ll i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;
        dp[i] = max(dp[i - 1] + sum[x], suff[x]);
        ans = max({ans, dp[i], dp[i - 1] + pref[x], pref[x], mx[x]});
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
