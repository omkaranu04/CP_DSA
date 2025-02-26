#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9 + 7;
ll n, x;
vector<ll> c, dp;
ll rec(ll rem_amt)
{
    if (rem_amt == 0)
        return 1;

    if (dp[rem_amt] != -1)
        return dp[rem_amt];

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (rem_amt - c[i] >= 0)
            ans = (ans + rec(rem_amt - c[i])) % mod;
    }

    return dp[rem_amt] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    c.resize(n);
    dp.resize(x + 1, -1);
    for (ll i = 0; i < n; i++)
        cin >> c[i];
    cout << rec(x) << endl;
    return 0;
}