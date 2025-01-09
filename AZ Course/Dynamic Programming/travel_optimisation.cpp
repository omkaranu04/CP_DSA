#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
int n, m, k;
vector<int> a, b;
// vector<vector<int>> dp, dp3;
// int rec(int idx, int flights)
// {
//     // pruning and base cases
//     if (idx >= n)
//         return 1e9;
//     if (flights < 0)
//         return 1e9;
//     if (idx == n - 1)
//         return 0;

//     if (dp[idx][flights] != -1)
//         return dp[idx][flights];

//     int ans = 1e9;

//     // take the bus
//     ans = min(ans, rec(idx + 1, flights) + a[idx]);

//     // take flights
//     for (int j = idx + 1; j <= min(n - 1, idx + k); j++)
//     {
//         ans = min(ans, rec(j, flights - 1) + b[j] + b[idx]);
//     }

//     return dp[idx][flights] = ans;
// }
// int rec2(int idx, int flights)
// {
//     if (idx < 0)
//         return 1e9;
//     if (flights < 0)
//         return 1e9;
//     if (idx == 0)
//         return 0;

//     if (dp3[idx][flights] != -1)
//         return dp3[idx][flights];

//     int ans = 1e9;

//     // take the bus
//     ans = min(ans, rec2(idx - 1, flights) + a[idx - 1]);

//     // take flights
//     for (int j = idx - 1; j >= max(1, idx - k); j--)
//     {
//         ans = min(ans, rec2(j, flights - 1) + b[j] + b[idx]);
//     }

//     return dp3[idx][flights] = ans;
// }
void solve()
{
    // cin >> n >> m >> k;
    // a.resize(n);
    // b.resize(n);
    // for (int i = 0; i < n; i++)
    //     cin >> a[i];
    // for (int i = 0; i < n; i++)
    //     cin >> b[i];

    // dp.resize(n + 1, vector<int>(m + 1, -1));
    // int ans = 1e9;
    // for (int f = 0; f <= m; f++)
    // {
    //     ans = min(ans, rec(0, f));
    // }
    // cout << "rec : ";
    // cout << ans << endl;

    // dp3.resize(n + 1, vector<int>(m + 1, -1));
    // int anss = 1e9;
    // for (int f = 0; f <= m; f++)
    // {
    //     anss = min(anss, rec2(n - 1, f));
    // }
    // cout << "rec2 : ";
    // cout << anss << endl;

    // iterative dp
    // vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));

    // for (int idx = n - 1; idx >= 0; idx--)
    // {
    //     for (int flights = 0; flights <= m; flights++)
    //     {
    //         // base case
    //         if (idx == n - 1)
    //         {
    //             dp2[idx][flights] = 0;
    //             continue;
    //         }

    //         int ans = 1e9;

    //         // take the bus
    //         ans = min(ans, dp2[idx + 1][flights] + a[idx]);

    //         // take flights
    //         if (flights > 0)
    //         {
    //             for (int j = idx + 1; j <= min(n - 1, idx + k); j++)
    //             {
    //                 ans = min(ans, dp2[j][flights - 1] + b[j] + b[idx]);
    //             }
    //         }

    //         dp2[idx][flights] = ans;
    //     }
    // }
    // cout << "it : ";
    // cout << dp2[0][m] << endl;

    // iterative dp2
    // vector<vector<int>> dp4(n + 1, vector<int>(m + 1, 0));
    // for (int idx = 0; idx < n; idx++)
    // {
    //     for (int flights = 0; flights <= m; flights++)
    //     {
    //         if (idx == 0)
    //         {
    //             dp4[idx][flights] = 0;
    //             continue;
    //         }

    //         int ans = 1e9;
    //         // take the bus
    //         ans = min(ans, dp4[idx - 1][flights] + a[idx - 1]);

    //         // take flights
    //         if (flights > 0)
    //         {
    //             for (int j = idx - 1; j >= max(1, idx - k); j--)
    //             {
    //                 ans = min(ans, dp4[j][flights - 1] + b[j] + b[idx]);
    //             }
    //         }

    //         dp4[idx][flights] = ans;
    //     }
    // }
    // cout << "it2 : ";
    // cout << dp4[n - 1][m] << endl;

    // space optimisation step 1 on iterative dp
    // vector<vector<int>> dp5(n + 1, vector<int>(2, 0));
    // for (int flights = 0; flights <= m; flights++)
    // {
    //     dp5[0][flights] = 0;
    // }
    // for (int idx = 1; idx < n; idx++)
    // {
    //     for (int flights = 0; flights <= m; flights++)
    //     {
    //         int ans = 1e9;
    //         // take the bus
    //         ans = min(ans, dp5[idx - 1][flights & 1] + a[idx - 1]);

    //         // take flights
    //         if (flights > 0)
    //         {
    //             for (int j = idx - 1; j >= max(1, idx - k); j--)
    //             {
    //                 ans = min(ans, dp5[j][(flights - 1) & 1] + b[j] + b[idx]);
    //             }
    //         }

    //         dp5[idx][flights & 1] = ans;
    //     }
    // }
    // cout << "it3 : ";
    // cout << dp5[n - 1][m & 1] << endl;

    // space optimisation step 2 on iterative dp
    cin >> n >> m >> k;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        cin >> b[i];

    // iska deque waala logic samajna hai, jyada samaj mein nahi aaya
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 1e18));
    dp[1][0] = 0;
    ll ans = 1e18;
    for (int j = 0; j <= m; j++)
    {
        deque<int> dq;
        dq.push_front(1);
        for (int i = 2; i <= n; i++)
        {
            dp[i][j & 1] = min(dp[i][j & 1], dp[i - 1][j & 1] + a[i - 1]);
            if (j == 0)
                continue;
            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();
            dp[i][j & 1] = min(dp[i][j & 1], dp[dq.front()][(j - 1) & 1] + b[dq.front()] + b[i]);
            while (!dq.empty() && dp[dq.back()][(j - 1) & 1] + b[dq.back()] >= dp[i][(j - 1) & 1] + b[i])
                dq.pop_back();
            dq.push_back(i);
        }
        ans = min(ans, dp[n][j & 1]);
    }
    cout << ans << endl;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}