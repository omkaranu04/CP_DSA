#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
ll dp[1300][1300];
ll ans[1300];
// dp[i][j] --> subseqs of size j using array values upto i
void solve()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        mp[a]++;
    }
    vector<ll> freq;
    for (auto i : mp)
        freq.push_back(i.second);
    memset(dp, 0, sizeof(dp));
    // dp[i][j] --> subseqs of size j using array values upto i
    for (int i = 0; i < freq.size(); i++)
        dp[i][0] = 1; // empty subseqs cnt = 1
    // using first val
    dp[0][1] = freq[0];
    for (int i = 1; i < freq.size(); i++)
    {
        for (int j = 1; j <= freq.size(); j++)
        {
            // not take
            dp[i][j] += dp[i - 1][j]; // skip index
            dp[i][j] %= mod;
            // consider taking
            dp[i][j] += dp[i - 1][j - 1] * freq[i] * 1LL;
            dp[i][j] %= mod;
        }
    }
    memset(ans, 0, sizeof(ans));
    ans[0] = 1; // empty
    for (int i = 1; i <= freq.size(); i++)
    {
        ans[i] = ans[i - 1] + dp[freq.size() - 1][i];
        ans[i] %= mod;
    }
    ll a = (k <= freq.size()) ? ans[k] : ans[freq.size()];
    cout << a << "\n";
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