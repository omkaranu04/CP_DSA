#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int m;
    scanf("%d", &m);
    int output[m];
    for (int k = 0; k < m; k++)
    {
        int flag = 0;
        int n, i;
        scanf("%d", &n);
        char sequence[n + 1];
        scanf("%s", sequence);
        int task[26] = {0};
        for (i = 1; i < n + 1; i++)
        {
            if (sequence[i - 1] == sequence[i])
                continue;
            else
            {
                int t = sequence[i - 1];
                if (task[t - 65] == 1)
                {
                    output[k] = 0;
                    flag = 1;
                }
                else
                {
                    task[t - 65] = 1;
                }
            }
        }
        if (i == n + 1 && flag == 0)
            output[k] = 1;
    }
    for (int o = 0; o < m; o++)
    {
        if (output[o] == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
