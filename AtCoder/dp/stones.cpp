#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a, dp;
int rec(int rem_stones)
{
    if (rem_stones == 0)
        return dp[rem_stones] = 0;

    if (dp[rem_stones] != -1)
        return dp[rem_stones];

    for (auto i : a)
    {
        if (rem_stones - i >= 0 && rec(rem_stones - i) == 0)
            return dp[rem_stones] = 1;
    }

    return dp[rem_stones] = 0;
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    dp.resize(k + 1, -1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // RECURSION FAIL ON MANY TEST CASES (RECUSTION STACK DEPTH)
    // cout << (rec(k) ? "First" : "Second") << endl;

    // iter solution
    vector<bool> dp2(k + 1, false);
    for (int i = 0; i <= k; i++)
    {
        for (int x : a)
        {
            if (i - x >= 0 && dp2[i - x] == false)
            {
                dp2[i] = true;
            }
        }
    }
    cout << (dp2[k] ? "First" : "Second") << endl;
    return 0;
}