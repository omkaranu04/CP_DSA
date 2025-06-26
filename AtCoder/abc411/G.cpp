#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 998244353;
ll modpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = modpow(a, b / 2);
    res = (res * 1LL * res) % mod;
    if (b % 2)
        res = (res * 1LL * a) % mod;
    return res;
}
const ll inv2 = modpow(2, mod - 2);
ll nc2(ll n)
{
    ll ret = n * 1LL * (n - 1) % mod * inv2;
    return ret;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n, vector<ll>(n, 0));
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u][v]++;
        adj[v][u]++;
    }
    ll ans1 = 0; // parallel edges cycle
    for (ll u = 0; u < n; u++)
    {
        for (ll v = u + 1; v < n; v++)
        {
            if (adj[u][v] >= 2)
            {
                ans1 += nc2(adj[u][v]);
                ans1 %= mod;
            }
        }
    }
    ll ans2 = 0; // rest cycles
    for (ll s = 0; s < n; s++)
    {
        vector<ll> vertices;
        for (ll v = s + 1; v < n; v++)
            vertices.push_back(v);
        ll k = vertices.size();
        if (k < 2)
            continue;

        vector<vector<ll>> dp(1LL << k, vector<ll>(k, 0));
        for (ll i = 0; i < k; i++)
        {
            if (adj[s][vertices[i]])
                dp[1LL << i][i] = adj[s][vertices[i]] % mod;
        }
        for (ll mask = 1; mask < (1LL << k); mask++)
        {
            ll ones = (ll)__builtin_popcount(mask);
            for (ll last = 0; last < k; last++)
            {
                if ((mask & (1LL << last)) == 0)
                    continue;
                ll curr = dp[mask][last];
                if (curr == 0)
                    continue;

                ll u = vertices[last];
                if (ones >= 2 && adj[u][s])
                {
                    ans2 += (curr * 1LL * adj[u][s]) % mod;
                    ans2 %= mod;
                }

                for (ll aage = 0; aage < k; aage++)
                {
                    if ((mask & (1LL << aage)))
                        continue;
                    ll v = vertices[aage];
                    ll ways = adj[u][v];
                    if (ways == 0)
                        continue;

                    ll nmask = mask | (1LL << aage);
                    dp[nmask][aage] += (curr * 1LL * ways) % mod;
                    dp[nmask][aage] %= mod;
                }
            }
        }
    }
    ll ans = (ans1 + ans2 * inv2) % mod;
    cout << ans;
    return 0;
}