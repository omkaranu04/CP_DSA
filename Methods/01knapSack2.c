#include <stdio.h>
int dp[1000][1000];
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int knapSack(int rem_wgt, int idx, int wt[], int val[])
{
    if (rem_wgt == 0)
        return 0;
    if (idx < 0)
        return 0;
    if (dp[idx][rem_wgt] != -1)
        return dp[idx][rem_wgt];
    int ans = knapSack(rem_wgt, idx - 1, wt, val);
    if (rem_wgt - wt[idx] >= 0)
        ans = max(ans, knapSack(rem_wgt - wt[idx], idx - 1, wt, val) + val[idx]);
    return dp[idx][rem_wgt] = ans;
}
int main(int argc, char const *argv[])
{
    int wt[] = {3, 4, 6, 5};
    int val[] = {2, 3, 1, 4};
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp[i][j] = -1;
        }
    }

    printf("%d", knapSack(8, 3, wt, val));
    return 0;
}