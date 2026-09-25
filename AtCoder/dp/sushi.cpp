#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll MAXN = 310;
ll N;
ld dp[MAXN][MAXN][MAXN];
ll a[MAXN];
ld rec(ll x, ll y, ll z)
{
    // base case
    if(x == 0 && y == 0 && z == 0) return 0.0;
    // dp check and return
    if(dp[x][y][z] != -1.0) return dp[x][y][z];
    // transition
    ld ans = (ld)N;
    if(x - 1 >= 0) ans += (ld)x * rec(x - 1, y, z);
    if(y - 1 >= 0) ans += (ld)y * rec(x + 1, y - 1, z);
    if(z - 1 >= 0) ans += (ld)z * rec(x, y + 1, z - 1);
    ans = ans / (ld)(x + y + z);
    // return
    return dp[x][y][z] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&dp[0][0][0], &dp[0][0][0] + MAXN * MAXN * MAXN, -1.0);
    cin >> N;
    ll x = 0, y = 0, z = 0;
    for (ll i = 1; i <= N; i++)
    {
        cin >> a[i];
        if(a[i] == 1) x++;
        if(a[i] == 2) y++;
        if(a[i] == 3) z++;
    }
    cout << setprecision(20) << rec(x, y, z);
    return 0;
}