#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 100100;
vector<ll> fact(MAXN), ifact(MAXN);
vector<pair<ll, ll>> tc;
ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res = (res * 1LL * res) % MOD;
    if (b % 2)
        res = (res * 1LL * a) % MOD;
    return res;
}
void pre()
{
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * 1LL * i) % MOD;
    ifact[MAXN - 1] = binpow(fact[MAXN - 1], MOD - 2);
    for (ll i = MAXN - 2; i >= 0; i--)
        ifact[i] = (ifact[i + 1] * 1LL * (i + 1)) % MOD;
}
inline ll ncr(ll n, ll r) { return ((fact[n] * 1LL * ifact[r]) % MOD * 1LL * ifact[n - r]) % MOD; }

ll solve(ll n, ll m)
{
    ll k = m - 1;
    vector<ll> suf(n + 1, 0);
    ll curr = 0;
    for (ll i = n; i >= 1; i--)
    {
        curr = (curr + ncr(n - i + k, k)) % MOD;
        suf[i] = curr;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
        ans = (ans + suf[i] * 1LL * ncr(i + k - 1, k)) % MOD;
    return ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n, m;
        cin >> n >> m;
        tc.push_back({n, m});
    }
    for (auto x : tc)
        cout << solve(x.first, x.second) << endl;
    return 0;
}