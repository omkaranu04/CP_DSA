#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 5010;
ll N;
ll x[MAXN], dp[MAXN][MAXN];
// dp -> what is the maximum score achieved by player 1 when it is his turn (t = 0)
ll rec(ll i, ll j)
{
    if (i > j)
        return 0;
    if (dp[i][j] != LLONG_MIN)
        return dp[i][j];
    ll tl = x[i] - rec(i + 1, j);
    ll tr = x[j] - rec(i, j - 1);
    return dp[i][j] = max(tl, tr);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (ll i = 0; i <= N; i++)
        for (ll j = 0; j <= N; j++)
            dp[i][j] = LLONG_MIN;
    for (ll i = 1; i <= N; i++)
        cin >> x[i];
    ll s = 0;
    for (ll i = 1; i <= N; i++)
        s += x[i];
    ll d = rec(1, N);
    cout << (s + d) / 2;
    return 0;
}