#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[5][5], row, col;
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
            {
                row = i;
                col = j;
            }
        }
    }
    if (row > 2)
    {
        while (row > 2)
        {
            row--;
            count++;
        }
    }
    if (row < 2)
    {
        while (row < 2)
        {
            row++;
            count++;
        }
    }
    if (col > 2)
    {
        while (col > 2)
        {
            col--;
            count++;
        }
    }
    if (col < 2)
    {
        while (col < 2)
        {
            col++;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
