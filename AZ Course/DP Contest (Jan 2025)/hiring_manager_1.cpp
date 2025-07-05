#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll mod = 1e9 + 7;
ll N, H, S, T;
ll A[110];
ll dp[110][110];
ll rec(ll i, ll emp)
{
    if (i > N)
        return emp * T;
    if (dp[i][emp] != -1)
        return dp[i][emp];
    ll ans = LLONG_MAX;
    for (ll nemp = A[i]; nemp <= 100; nemp++)
    {
        ll cost = 0;
        if (nemp > emp)
            cost += H * llabs(nemp - emp);
        else
            cost += T * llabs(nemp - emp);
        cost += nemp * S;
        cost += rec(i + 1, nemp);
        ans = min(ans, cost);
    }
    return dp[i][emp] = ans;
}
void solve()
{
    cin >> N >> H >> S >> T;
    for (ll i = 1; i <= N; i++)
        cin >> A[i];
    memset(dp, -1, sizeof(dp));
    cout << rec(1, 0) << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}