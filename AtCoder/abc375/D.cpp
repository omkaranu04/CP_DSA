#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    ll n = s.size();
    vector<vector<ll>> dp(26, vector<ll>(n + 1));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < 26; j++)
        {
            dp[j][i + 1] = dp[j][i];
        }
        dp[s[i] - 'A'][i + 1]++;
    }
    ll ans = 0;
    for (ll i = 1; i < n - 1; i++)
    {
        for (ll j = 0; j < 26; j++)
        {
            ll l = dp[j][i];
            ll r = dp[j][n] - dp[j][i + 1];
            ans += l * r;
        }
    }
    cout << ans << endl;
    return 0;
}