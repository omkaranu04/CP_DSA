#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, C;
vector<ll> h, dp;
ll rec(ll i)
{
    if (i == 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    ll ans = LLONG_MAX;
    for (ll j = i - 1; j >= 1; j--)
    {
        ll cost = (h[i] - h[j]) * (h[i] - h[j]) + C;
        ans = min(ans, cost + rec(j));
    }
    return dp[i] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> C;
    h.resize(N + 1);
    for (ll i = 1; i <= N; i++)
        cin >> h[i];

    dp.resize(N + 1, -1);
    cout << rec(N);
    return 0;
}