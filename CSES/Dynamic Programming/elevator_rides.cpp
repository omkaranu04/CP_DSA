#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, x;
vector<ll> w;
vector<bool> vis;
vector<pair<ll, ll>> dp;
// dp[mask] = (r, w) --> r = minimum number of rides required, w = weight currently occupied in last ride
pair<ll, ll> rec(ll mask)
{
    if (mask == 0)
        return {1, 0};
    if (vis[mask])
        return dp[mask];
    vis[mask] = true;
    pair<ll, ll> ans = {LLONG_MAX, LLONG_MAX};
    for (ll i = 0; i < n; i++)
    {
        if (!(mask & (1LL << i)))
            continue;
        auto [r, ww] = rec(mask ^ (1LL << i));
        if (ww + w[i] <= x)
            ans = min(ans, {r, ww + w[i]});
        else
            ans = min(ans, {r + 1, w[i]});
    }
    return dp[mask] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    w.resize(n);
    for (auto &x : w)
        cin >> x;
    ll tot = 1LL << n;
    vis.resize(tot, false);
    dp.resize(tot);
    auto ans = rec((1LL << n) - 1);
    cout << ans.first << endl;
    return 0;
}