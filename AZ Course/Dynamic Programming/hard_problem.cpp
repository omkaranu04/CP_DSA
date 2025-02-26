#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> cost(n);
    for (ll i = 0; i < n; i++)
        cin >> cost[i];
    vector<ll> dp(4, 0);
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'h')
            dp[0] += cost[i];
        else if (s[i] == 'a')
            dp[1] = min(dp[0], dp[1] + cost[i]);
        else if (s[i] == 'r')
            dp[2] = min(dp[1], dp[2] + cost[i]);
        else if (s[i] == 'd')
            dp[3] = min(dp[2], dp[3] + cost[i]);
    }
    cout << dp[3] << endl;
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