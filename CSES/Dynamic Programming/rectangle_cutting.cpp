#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a, b;
ll dp[510][510];
ll rec2(ll a, ll b)
{
    if (a == b)
        return 0;

    if (dp[a][b] != -1)
        return dp[a][b];

    ll ans = 1e9;
    for (int i = 1; i < a; i++)
    {
        ans = min(ans, rec2(i, b) + rec2(a - i, b) + 1);
    }
    for (int i = 1; i < b; i++)
    {
        ans = min(ans, rec2(a, i) + rec2(a, b - i) + 1);
    }
    return dp[a][b] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << rec2(a, b) << endl;
    return 0;
}