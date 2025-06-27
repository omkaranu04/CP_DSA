#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, a[512], dp[512][512];
ll rec(ll l, ll r)
{
    if(l >= r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll ans = LLONG_MAX, sum = 0, curr = 0;
    for(ll i = l; i <= r; i++)
        sum += a[i];

    for(ll mid = l; mid <= r - 1; mid++)
    {
        curr += a[mid];
        ll tmp = rec(l, mid) + rec(mid + 1, r) + (curr + (sum - curr));
        ans = min(ans, tmp);
    }

    return dp[l][r] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (ll i = 1; i <= N; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));
    cout << rec(1, N);
    return 0;
}