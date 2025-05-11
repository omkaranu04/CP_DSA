#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
const ll MOD = 1e9 + 7;
const ll MAX = 1000100;
vector<bool> prime(MAX, true);
void init()
{
    prime[0] = prime[1] = false;
    for (ll i = 2; i * i <= MAX; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j <= MAX; j += i)
                prime[j] = false;
        }
    }
}
void solve()
{
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == 0)
            continue;
        ll num = 0;
        for (ll len = 1; len <= 6 && i + len <= n; len++)
        {
            if (len > 1 && s[i] == '0')
                break;
            num = num * 10 + (s[i + len - 1] - '0');
            if (num > MAX)
                break;
            if (prime[num])
                dp[i + len] = (dp[i + len] + dp[i]) % MOD;
        }
    }
    cout << dp[n] << endl;
}
int main()
{
    init();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}