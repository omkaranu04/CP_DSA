#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
ll n;
ld p[3010];
ld dp[3010][3010];
bool vis[3010][3010];

ld rec(ll i, ll heads)
{
    if (i > n)
    {
        ll tails = n - heads;
        if (heads > tails)
            return 1.0;
        else
            return 0.0;
    }
    if (vis[i][heads])
        return dp[i][heads];

    ld ans = p[i] * rec(i + 1, heads + 1) + (1 - p[i]) * rec(i + 1, heads);

    vis[i][heads] = true;
    return dp[i][heads] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> p[i];

    memset(vis, false, sizeof(vis));
    memset(dp, 1.0, sizeof(dp));
    cout << setprecision(10) << rec(1, 0);
    return 0;
}