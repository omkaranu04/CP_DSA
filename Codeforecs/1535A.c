#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main(int argc, char const *argv[])
{
    int n, a[4];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < 4; i++)
        {
            scanf("%d", &a[i]);
        }

        int max1 = max(a[0], a[1]);
        int max2 = max(a[2], a[3]);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3 - i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int t = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = t;
                }
            }
        }
        if ((max1 == a[2] && max2 == a[3]) || (max1 == a[3] && max2 == a[2]))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
