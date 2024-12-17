#include <stdio.h>
int min(int amt)
{
    int c, count1, count2;
    c = amt / 3;
    count1 = count2 = c;
    if (amt % 3 == 2)
        count2 = count2 + 1;
    else if (amt % 3 == 1)
        count1 = count1 + 1;
    printf("%d  %d\n", count1, count2);
}
int main(int argc, char const *argv[])
{
    int amt, n;
    scanf("%d", &n);
    for (int u = 1; u <= n; u++)
    {
        scanf("%d", &amt);
        min(amt);
    }
    return 0;
}
