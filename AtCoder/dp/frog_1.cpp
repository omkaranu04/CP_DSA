#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
vector<ll> h;
vector<ll> dp;
ll rec(ll level)
{
    if (level == n - 1)
        return 0;
    if (dp[level] != -1)
        return dp[level];
    ll ans = INT_MAX;
    if (level + 1 < n)
        ans = min(ans, rec(level + 1) + abs(h[level] - h[level + 1]));
    if (level + 2 < n)
        ans = min(ans, rec(level + 2) + abs(h[level] - h[level + 2]));
    return dp[level] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    h.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    dp.resize(n + 2, -1);
    cout << rec(0) << endl;
    return 0;
}