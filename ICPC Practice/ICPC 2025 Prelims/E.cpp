#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 998244353;
const ll MAXN = 200010;
ll fact[MAXN], ifact[MAXN];
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll t = modpow(a, b / 2);
    t = (t * t) % MOD;
    if (b % 2 == 0)
        return t;
    return (t * a) % MOD;
}
ll nCr(ll n, ll r) { return (r < 0 || r > n) ? 0 : fact[n] * ifact[r] % MOD * ifact[n - r] % MOD; }
void dfs(ll u, ll p, ll d, vector<ll> &dep, vector<vector<ll>> &g)
{
    dep[u] = d;
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u, d + 1, dep, g);
    }
}
void clove()
{
    ll n, c;
    cin >> n >> c;
    vector<vector<ll>> g(n + 1);
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> dep(n + 1, 0);
    dfs(1, 0, 0, dep, g);
    ll ansc = 0, ansc1 = 0;
    // for (ll i = 1; i <= n; i++)
    //     cout << "dep " << i << " " << dep[i] << endl;
    for (ll i = 1; i <= n; i++)
    {
        if (i == 1)
            continue;

        ll t1 = modpow(2, c - 1);
        ll t2 = nCr(dep[i] - 1, c - 1);
        ll t3 = fact[n - c - 1];
        // cout << t1 << " " << t2 << " " << t3 << endl;
        ansc = (ansc + ((t1 * t2) % MOD * t3) % MOD) % MOD;
        // cout << ((t1 * t2) % MOD * t3) % MOD << endl;

        t1 = modpow(2, c);
        t2 = nCr(dep[i] - 1, c);
        t3 = fact[n - c - 2];
        // cout << t1 << " " << t2 << " " << t3 << endl;
        ansc1 = (ansc1 + ((t1 * t2) % MOD * t3) % MOD) % MOD;
        // cout << ((t1 * t2) % MOD * t3) % MOD << endl;
    }
    cout << (ansc - ansc1 + MOD) % MOD << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    ifact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (ll i = MAXN - 1; i >= 1; i--)
        ifact[i - 1] = (ifact[i] * i) % MOD;
    ll T;
    cin >> T;
    while (T--)
    {
        clove();
    }
    return 0;
}