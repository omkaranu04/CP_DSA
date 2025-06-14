#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll n, dp[(1 << 20) + 10];
vector<ll> a;
ll play(ll board, ll mask) // mask the players
{
    if (mask == (1 << (2 * n)) - 1)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    ll ans = -1;
    for (ll i = 0; i < 2 * n; i++)
    {
        if ((mask & (1 << i)) == 0)
        {
            for (ll j = i + 1; j < 2 * n; j++)
            {
                if ((mask & (1 << j)) == 0)
                {
                    ll temp = (board + 1) * abs(a[i] - a[j]) * __gcd(a[i], a[j]);
                    ans = max(ans, temp + play(board + 1, (mask | (1 << i) | (1 << j))));
                }
            }
        }
    }

    return dp[mask] = ans;
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
        cin >> n;
        a.resize(2 * n);
        for (ll i = 0; i < 2 * n; i++)
            cin >> a[i];
        memset(dp, -1, sizeof(dp));
        cout << play(0, 0) << endl;
    }
    return 0;
}