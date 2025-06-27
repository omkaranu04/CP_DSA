#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll n, k;
ll dp[4000][4000];
ll ans[5000];
// dp[i][j] -> subsequence of length j using elements uptil i
void solve()
{
    cin >> n >> k;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x]++;
    }
    vector<ll> freq;
    for (auto x : mp)
        freq.push_back(x.second);
    ll m = freq.size();

    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < m; i++)
        dp[i][0] = 1;
    dp[0][1] = freq[0];
    for (ll i = 1; i < m; i++) // index
    {
        for (ll j = 1; j <= m; j++) // length
        {
            // take
            dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * 1LL * freq[i]) % mod;
            // no take
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
    }
    memset(ans, 0, sizeof(ans));
    ans[0] = 1;
    for (ll i = 1; i <= m; i++)
        ans[i] = (ans[i] + ans[i - 1] + dp[m - 1][i]) % mod;
    cout << ((k <= m ? ans[k] : ans[m])) << endl;
    return;
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