#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, x;
vector<int> c;
vector<vector<int>> dp;
int rec(int index, int rem_amt)
{
    if (rem_amt == 0)
        return 1;
    if (index == 0 || rem_amt < 0)
        return 0;

    if (dp[index][rem_amt] != -1)
        return dp[index][rem_amt];

    int ans = 0;
    ans = (ans + rec(index - 1, rem_amt)) % mod;
    if (rem_amt >= c[index - 1])
        ans = (ans + rec(index, rem_amt - c[index - 1])) % mod;

    return dp[index][rem_amt] = ans;
}
int main(int argc, char const *argv[])
{
    cin >> n >> x;
    c.resize(n);
    dp.resize(n + 1, vector<int>(x + 1, -1));
    for (int i = 0; i < n; i++)
        cin >> c[i];
    int ans = rec(n, x);
    cout << ans << endl;
    return 0;
}