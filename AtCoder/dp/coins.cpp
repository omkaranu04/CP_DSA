#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
ll N;
const ll MAXN = 3010;
bool vis[MAXN][MAXN];
ld dp[MAXN][MAXN], p[MAXN];
ld rec(ll i, ll h)
{
    // base case
    if (i > N)
    {
        ll t = N - h;
        if (h > t)
            return 1.0;
        else
            return 0.0;
    }
    // dp check and return
    if (vis[i][h])
        return dp[i][h];
    // transition
    ld ans = p[i] * rec(i + 1, h + 1) + (1.0 - p[i]) * rec(i + 1, h);
    // return
    vis[i][h] = true;
    return dp[i][h] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(vis, false, sizeof(vis));
    memset(dp, 1.0, sizeof(dp));
    cin >> N;
    for (ll i = 1; i <= N; i++)
        cin >> p[i];
    cout << setprecision(15) << rec(1, 0);
    return 0;
}