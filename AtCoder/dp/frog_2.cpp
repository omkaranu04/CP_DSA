#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n, k;
vector<ll> h;
vector<ll> dp;
int rec(int level)
{
    if (level == n - 1)
        return 0;
    if (dp[level] != -1)
        return dp[level];

    ll ans = INT_MAX;
    for (int i = 1; i <= k && level + i < n; i++)
    {
        ans = min(ans, rec(level + i) + abs(h[level] - h[level + i]));
    }
    return dp[level] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    h.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    dp.resize(n + 2, -1);
    cout << rec(0) << endl;
    return 0;
}