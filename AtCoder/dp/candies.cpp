#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, k;
vector<int> a;
vector<vector<int>> dp;
int rec(int idx, int rem)
{
    if (rem == 0)
        return 1;
    if (idx == n)
        return rem == 0;

    if (dp[idx][rem] != -1)
        return dp[idx][rem];

    int ans = 0;
    for (int i = 0; i <= min(rem, a[idx]); i++)
    {
        ans += rec(idx + 1, rem - i);
        ans %= mod;
    }
    return dp[idx][rem] = ans;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    dp.assign(n + 1, vector<int>(k + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << rec(0, k) << endl;
    return 0;
}