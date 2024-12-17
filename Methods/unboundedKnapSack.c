#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int w = 0; w < W + 1; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i][w - wt[i - 1]] + val[i - 1]);
                // dp[i][w] = dp[i - 1][w] + dp[i-1][w - wt[i - 1]] + val[i - 1]; -> ye 0/1 knapsack ke liye hai
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main(int argc, char const *argv[])
{
    int W[] = {1, 2, 3};
    int p[] = {1, 2, 3};
    printf("%d", knapSack(4, W, p, 3));
    return 0;
}