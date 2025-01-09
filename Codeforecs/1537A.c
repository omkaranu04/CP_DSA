#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[50], n, cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        int sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            sum = sum + a[i];
        }

        if (sum == n)
            printf("%d\n", 0);
        if (sum > n)
            printf("%d\n", sum - n);
        if (sum < n)
            printf("%d\n", 1);
    }

    return 0;
}
