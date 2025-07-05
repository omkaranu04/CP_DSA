#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
ll N, K;
vector<ll> d[2001];
ll dp[2001][2001], ps[2001][2001];
ll rec(ll i, ll n)
{
    if (i == 1)
        return 1;
    if (dp[i][n] != -1)
        return dp[i][n];
    ll ans = 0;
    for (auto num : d[n])
        ans = (ans + rec(i - 1, num)) % MOD;
    return dp[i][n] = ans;
}
void divisors()
{
    for (ll i = 1; i <= 2000; i++)
    {
        for (ll j = i; j <= 2000; j += i)
            d[j].push_back(i);
    }
}
void precomp()
{
    for (ll i = 1; i <= 2000; i++)
    {
        for (ll j = 1; j <= 2000; j++)
        {
            dp[i][j] = rec(i, j);
            ps[i][j] = ps[i][j - 1] + dp[i][j];
            ps[i][j] %= MOD;
        }
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    ll t;
    cin >> t;
    divisors();
    precomp();
    while (t--)
    {
        cin >> N >> K;
        cout << ps[K][N] << endl;
    }
    return 0;
}