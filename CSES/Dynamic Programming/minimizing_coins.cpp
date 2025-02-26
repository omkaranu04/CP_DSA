#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, x;
vector<ll> c;
vector<ll> dp;
vector<bool> vis;
ll rec(int amt)
{
    if (amt == 0)
        return 0;
    if (amt < 0)
        return -1;

    if (vis[amt])
        return dp[amt];

    ll ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (amt - c[i] >= 0)
        {
            ll temp = rec(amt - c[i]);
            if (temp != -1)
            {
                ans = min(ans, temp + 1);
            }
        }
    }

    vis[amt] = true;
    (ans == 1e9) ? dp[amt] = -1 : dp[amt] = ans;
    return dp[amt];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> x;
    c.resize(n);
    dp.resize(x + 1, -1);
    vis.resize(x + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    ll ans = rec(x);
    // cout << ((ans == 1e9) ? -1 : ans) << endl;
    cout << ans << endl;
    return 0;
}