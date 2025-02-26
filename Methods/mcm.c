#include <stdio.h>
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
int mcm(int arr[], int n)
{
    int dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int s = 1; s <= n - 1; s++)
    {
        for (int i = 1; i <= n - s; i++)
        {
            int j = i + s;
            dp[i][j] = __INT_MAX__;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }
    return dp[1][n - 1];
}
int main(int argc, char const *argv[])
{
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};
    printf("%d\n", mcm(arr, N));
    return 0;
}