#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
const ll MAXN = 1e7 + 10;
ll spf[MAXN], dp[MAXN];
void precompute()
{
    memset(spf, 0, sizeof(spf));
    for (ll i = 2; i < MAXN; i++)
    {
        if (spf[i])
            continue;
        spf[i] = i;
        for (ll j = i * i; j < MAXN; j += i)
            if (spf[j] == 0)
                spf[j] = i;
    }
}
void solve()
{
    memset(dp, 0, sizeof(dp));
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 1;
    for (ll x : a)
    {
        set<ll> s;
        while (x != 1)
        {
            ll p = spf[x];
            s.insert(p);
            while (x % p == 0)
                x /= p;
        }
        ll t = 0;
        for (auto p : s)
        {
            dp[p]++;
            ans = max(ans, dp[p]);
            t = max(t, dp[p]);
        }
        for (auto p : s)
            dp[p] = t;
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    precompute();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}