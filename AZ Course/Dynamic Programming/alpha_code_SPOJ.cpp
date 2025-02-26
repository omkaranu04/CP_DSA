#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll rec(string t)
{
    ll n = t.length();
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = (t[0] != '0') ? 1 : 0;

    for (int i = 2; i <= n; i++)
    {
        if (t[i - 1] != '0')
            dp[i] += dp[i - 1];
        ll temp = (t[i - 2] - '0') * 10 + (t[i - 1] - '0');
        if (temp >= 10 && temp <= 26)
            dp[i] += dp[i - 2];
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        string t;
        cin >> t;
        if (t == "0")
            break;
        ll ans = rec(t);
        cout << ans << endl;
    }
    return 0;
}