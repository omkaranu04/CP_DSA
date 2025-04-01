#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const int mod = 1e9 + 7;
ll n, m;
ll dp[1001][11][(1 << 10) + 1];
ll rec(ll i, ll j, ll mask)
{
    if (j == m)
        return rec(i + 1, 0, mask);
    if (i == n)
        return (mask == (1 << m) - 1);
    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];

    ll currbit = (mask & (1 << j));
    ll left_prev_bit = -1;
    if (j)
        left_prev_bit = (mask & (1 << (j - 1)));

    ll ans = 0;
    // upper cell exists and is empty
    if (i && !currbit)
    {
        // 2 x 1 vertical
        ll new_mask = mask | (1 << j);
        ans += rec(i, j + 1, new_mask);
        ans %= mod;
    }
    else if (j && !left_prev_bit) // prev cell exists and is empty
    {
        // 1 x 2 horizontal
        ll new_mask = mask | (1 << j) | (1 << (j - 1));
        ans += rec(i, j + 1, new_mask);
        ans %= mod;

        // leave blank and move forward
        ans += rec(i, j + 1, mask & (~(1 << j)));
        ans %= mod;
    }
    else // both cells do not exist or are both filled
    {
        ans += rec(i, j + 1, mask & (~(1 << j)));
        ans %= mod;
    }

    ans %= mod;
    return dp[i][j][mask] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        if (m > n)
            swap(n, m);
        cout << rec(0, 0, 0) << endl;
    }
    return 0;
}