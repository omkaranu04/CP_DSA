#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, even = 0, odd = 0, test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        scanf("%d", &n);
        int a[2 * n];
        for (int i = 0; i < 2 * n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < 2 * n; i++)
        {
            if (a[i] % 2 != 0)
                odd++;
            else
                even++;
        }
        if (even == odd)
            printf("Yes\n");
        else
            printf("No\n");
        odd = 0;
        even = 0;
    }
    return 0;
}
