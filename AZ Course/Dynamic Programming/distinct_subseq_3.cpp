#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
void solve()
{
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll dp[101][101], lastpos[26];
    // dp[i][j] -> distinct subsequences of length j till index i
    memset(dp, 0, sizeof(dp));
    memset(lastpos, 0, sizeof(lastpos));

    dp[0][0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        ll c = s[i - 1] - 'a';
        for (ll len = 0; len <= i; len++)
        {
            // not use s[i]
            ll val = dp[i - 1][len];
            if (len)
            {
                // append s[i] to all prev subseq
                val += dp[i - 1][len - 1];
                if (lastpos[c])
                    val -= dp[lastpos[c] - 1][len - 1];
            }
            val = max(0LL, val);
            val = min(val, k + 1);

            dp[i][len] = val;
        }
        lastpos[c] = i;
    }
    ll need = k, cost = 0;
    for (ll len = n; len >= 0 && need; len--)
    {
        ll take = min(need, dp[n][len]);
        cost += take * (n - len);
        need -= take;
    }
    if (need)
        cout << -1 << endl;
    else
        cout << cost << endl;
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