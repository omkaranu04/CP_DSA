#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MAXN = 1e6 + 10;
ll N;
ll dp[MAXN];
ll rec(ll rem)
{
    if (rem == 0)
        return 0;
    if (dp[rem] != -1)
        return dp[rem];
    vector<ll> dig;
    ll tmp = rem;
    while (tmp)
    {
        dig.push_back(tmp % 10);
        tmp /= 10;
    }
    ll ans = LLONG_MAX;
    for (auto d : dig)
    {
        if (rem - d >= 0 && d != 0)
            ans = min(ans, 1 + rec(rem - d));
    }
    return dp[rem] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    cout << rec(N);
    return 0;
}