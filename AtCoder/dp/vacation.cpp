#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll N;
vector<ll> a, b, c;
vector<vector<ll>> dp;
ll rec(ll level, ll prev)
{
    // base case
    if (level == N)
        return 0;
    if (dp[level][prev] != -1)
        return dp[level][prev];

    // based on prev_activity
    ll ans = 0;
    if (prev != 1)
        ans = max(ans, rec(level + 1, 1) + a[level]);
    if (prev != 2)
        ans = max(ans, rec(level + 1, 2) + b[level]);
    if (prev != 3)
        ans = max(ans, rec(level + 1, 3) + c[level]);

    return dp[level][prev] = ans;
}
int main(int argc, char const *argv[])
{
    cin >> N;
    a.resize(N);
    b.resize(N);
    c.resize(N);
    dp.resize(N + 1, vector<ll>(4, -1));
    for (ll i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    cout << rec(0, 0) << endl;
    return 0;
}