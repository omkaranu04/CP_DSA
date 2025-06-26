#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, X, Y, Z;
ll A[51], vis[51][51], dp[51][51][51];
ll rec(ll l, ll r, ll m)
{
    if (l == r)
    {
        if (A[l] == m)
            return 0;
        return 1e18;
    }
    if (vis[l][r])
        return dp[l][r][m];

    for (ll i = 0; i < 50; i++)
        dp[l][r][i] = 1e18;
    for (ll mid = l; mid < r; mid++)
    {
        for (ll ls = 0; ls < 50; ls++)
        {
            for (ll rs = 0; rs < 50; rs++)
            {
                ll val = (ls * X + rs * Y + Z) % 50;
                dp[l][r][val] = min(dp[l][r][val], rec(l, mid, ls) + rec(mid + 1, r, rs) + ls * rs);
            }
        }
    }

    vis[l][r] = 1;
    return dp[l][r][m];
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> X >> Y >> Z;
    for (ll i = 0; i < N; i++)
        cin >> A[i];

    memset(vis, 0, sizeof(vis));
    ll ans = 1e18;
    for (ll i = 0; i < 50; i++)
        ans = min(ans, rec(0, N - 1, i));

    cout << ans;
    return 0;
}