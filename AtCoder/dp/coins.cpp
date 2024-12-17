#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<double> p(n), dp(n + 1, 0.0); // dp of getting heads
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    dp[0] = 1.0; // base case
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            dp[j] = (j > 0 ? dp[j - 1] * p[i] : 0) + dp[j] * (1 - p[i]);
        }
    }
    double ans = 0.0;
    for (int i = (n + 1) / 2; i <= n; i++)
    {
        ans += dp[i];
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}