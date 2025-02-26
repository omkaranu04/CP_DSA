#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
ll n;
vector<ll> arr, dp, cnt;
void solve()
{
    cin >> n;
    arr.resize(n);
    dp.resize(n + 1, 0);
    cnt.resize(n + 1, 0);
    ll longest = 1;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 0; i < n; i++)
    {
        cnt[i] = 1;
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = (dp[j] + 1) % mod;
                    cnt[i] = cnt[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    cnt[i] = (cnt[i] + cnt[j]) % mod;
                }
            }
        }
        longest = max(longest, dp[i]);
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (longest == dp[i])
            ans = (ans + cnt[i]) % mod;
    }
    cout << ans << endl;
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