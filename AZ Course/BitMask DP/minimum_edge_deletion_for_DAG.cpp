#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n;
ll adj[16][16];
ll dp[16][1 << 16];
ll rec(ll pos, ll mask)
{
    if (pos == n + 1)
        return 0;
    if (dp[pos][mask] != -1)
        return dp[pos][mask];

    ll ans = 1e18;
    for (ll i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            continue;
        ll temp = 0;
        for (ll j = 0; j < n; j++)
        {
            if ((mask & (1 << j)))
                temp += adj[i][j];
        }
        ans = min(ans, rec(pos + 1, mask | (1 << i)) + temp);
    }

    return dp[pos][mask] = ans;
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
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                cin >> adj[i][j];
            }
        }
        cout << rec(1, 0) << endl;
    }
    return 0;
}