#include <stdio.h>
#include <string.h>

int dp[1000][1000];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char a[], char b[], int m, int n)
{
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

void buildLCS(char a[], char b[], int m, int n)
{
    char output[1000];
    int i = m, j = n, k = 0;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            output[k] = a[i - 1];
            i--;
            j--;
            k++;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    output[k] = '\0';

    // Reverse the LCS string before printing
    char reversed[1000];
    int len = strlen(output);
    for (int x = 0; x < len; x++)
    {
        reversed[x] = output[len - x - 1];
    }
    reversed[len] = '\0';

    printf("%s\n", reversed);
}

int main(int argc, char const *argv[])
{
    char a[] = "accggtcgag";
    char b[] = "gtcgtcggaatgc";
    int m = strlen(a);
    int n = strlen(b);
    int ans = lcs(a, b, m, n);
    printf("Length of LCS: %d\n", ans);
    buildLCS(a, b, m, n);
    return 0;
}
