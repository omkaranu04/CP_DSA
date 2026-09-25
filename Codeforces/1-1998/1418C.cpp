#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
const ll MOD = 1e9 + 7;
const ll MAXN = 200010;
ll N;
ll a[MAXN], dp[MAXN][2];
ll rec(ll i, ll p)
{
    // base case
    if (i > N)
        return 0;
    // dp check and return
    if (dp[i][p] != -1)
        return dp[i][p];
    // transitions
    if (p == 0)
    {
        // kill i
        ll t1 = 1e9, t2 = 1e9;
        if (a[i] == 1)
            t1 = rec(i + 1, 1 - p) + 1;
        else
            t1 = rec(i + 1, 1 - p);

        // kill i, and i + 1
        if (i + 1 <= N && a[i] == 1 && a[i + 1] == 1)
            t2 = rec(i + 2, 1 - p) + 2;
        if (i + 1 <= N && ((a[i] == 1 && a[i + 1] == 0) || a[i] == 0 && a[i + 1] == 1))
            t2 = rec(i + 2, 1 - p) + 1;
        if (i + 1 <= N && a[i] == 0 && a[i + 1] == 0)
            t2 = rec(i + 2, 1 - p);

        return dp[i][p] = min(t1, t2);
    }
    if (p == 1)
    {
        ll t1 = 1e9, t2 = 1e9;
        // kill i
        t1 = rec(i + 1, 1 - p);
        // kill i, and i + 1
        if (i + 1 <= N)
            t2 = rec(i + 2, 1 - p);

        return dp[i][p] = min(t1, t2);
    }
    // return
    return 0;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (ll i = 1; i <= N; i++)
            cin >> a[i];

        // for (ll i = 0; i <= N + 1; i++)
        // {
        //     dp[i][0] = -1;
        //     dp[i][1] = -1;
        // }
        // cout << rec(1, 0) << endl;

        // base case
        dp[N + 1][0] = 0;
        dp[N + 1][1] = 0;
        dp[N + 2][0] = 0;
        dp[N + 2][1] = 0;
        ll t1, t2;
        for (ll i = N; i >= 1; i--)
        {
            // p = 0
            t1 = 1e9;
            if (a[i] == 1)
                t1 = dp[i + 1][1] + 1;
            else
                t1 = dp[i + 1][1];

            t2 = 1e9;
            if (i + 1 <= N && a[i] == 1 && a[i + 1] == 1)
                t2 = dp[i + 2][1] + 2;
            if (i + 1 <= N && ((a[i] == 1 && a[i + 1] == 0) || a[i] == 0 && a[i + 1] == 1))
                t2 = dp[i + 2][1] + 1;
            if (i + 1 <= N && a[i] == 0 && a[i + 1] == 0)
                t2 = dp[i + 2][1];

            dp[i][0] = min(t1, t2);

            // p = 1
            t1 = 1e9;
            t1 = dp[i + 1][0];

            t2 = 1e9;
            if (i + 1 <= N)
                t2 = dp[i + 2][0];

            dp[i][1] = min(t1, t2);
        }
        cout << dp[1][0] << endl;
    }
    return 0;
}