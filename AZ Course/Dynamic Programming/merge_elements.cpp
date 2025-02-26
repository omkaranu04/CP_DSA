#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<vector<int>> dp;
int rec(int l, int r)
{
    if (l == r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int sum = 0, run_sum = 0, ans = 1e9;
    for (int i = l; i <= r; i++)
    {
        sum += a[i];
    }
    for (int i = l; i < r; i++)
    {
        run_sum += a[i];
        ans = min(ans, rec(l, i) + rec(i + 1, r) + (((run_sum) % 100) * ((sum - run_sum) % 100)));
    }

    return dp[l][r] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    dp.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << rec(0, n - 1) << endl;
    return 0;
}