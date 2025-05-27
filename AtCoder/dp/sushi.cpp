#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define endl "\n"
const ll mod = 1e9 + 7;
ll N;
vector<ll> a(310);
ld dp[310][310][310];
ld rec(ll x, ll y, ll z)
{
    if (x < 0 || y < 0 || z < 0)
        return 0.0;
    if (x == 0 && y == 0 && z == 0)
        return 0.0;
    if (dp[x][y][z] > 0)
        return dp[x][y][z];
    ld ans = N;
    ans += (ld)x * rec(x - 1, y, z);
    ans += (ld)y * rec(x + 1, y - 1, z);
    ans += (ld)z * rec(x, y + 1, z - 1);
    ans = (ld)ans / (ld)(x + y + z);

    return dp[x][y][z] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, 0.0, sizeof(dp));
    cin >> N;
    ll ones = 0, twos = 0, threes = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            ones++;
        if (a[i] == 2)
            twos++;
        if (a[i] == 3)
            threes++;
    }
    cout << fixed << setprecision(15) << rec(ones, twos, threes);
    return 0;
}