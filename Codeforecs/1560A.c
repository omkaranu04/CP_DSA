#include <stdio.h>
int main(int argc, char const *argv[])
{
    int m;
    scanf("%d", &m);
    for (int p = 0; p < m; p++)
    {
        int n, i = 0, j = 1;
        scanf("%d", &n);
        while (1)
        {
            for (i = 0; i < n;)
            {
                if ((j % 3 != 0) && (j % 10 != 3))
                {
                    i++;
                    // printf("%d ", j);
                }
                ++j;
            }
            if (i == n)
                break;
        }
        printf("%d\n", --j);
    }
    return 0;
}
