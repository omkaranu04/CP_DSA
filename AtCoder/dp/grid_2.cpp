#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 200200;
ll fact[MAXN], invfact[MAXN];
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = modpow(a, b / 2);
    res = (res * res) % MOD;
    if (b % 2)
        res = (res * a) % MOD;
    return res;
}
void initfact()
{
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (ll i = MAXN - 2; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
}
ll h, w, n;
vector<pair<ll, ll>> sq;
vector<ll> dp;
ll ncr(ll n, ll r)
{
    return (((fact[n] * invfact[r]) % MOD) * invfact[n - r]) % MOD;
}
ll path(ll x1, ll y1, ll x2, ll y2)
{
    return ncr(x2 - x1 + y2 - y1, x2 - x1);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    initfact();
    cin >> h >> w >> n;
    h--, w--;
    dp.resize(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        ll r, c;
        cin >> r >> c;
        r--, c--;
        sq.push_back({r, c});
    }
    sq.push_back({h, w});
    sort(sq.begin(), sq.end());

    // dp[i] -> number of ways to reach point i, w/o crossing any other points

    for (ll i = 0; i <= n; i++)
    {
        ll tot = path(0, 0, sq[i].first, sq[i].second);
        for (ll j = 0; j < i; j++)
        {
            if (sq[i].second - sq[j].second >= 0)
            {
                tot -= dp[j] * path(sq[j].first, sq[j].second, sq[i].first, sq[i].second) % MOD;
                if (tot < 0)
                    tot += MOD;
            }
        }
        dp[i] = tot;
    }
    cout << dp[n] << endl;
    return 0;
}