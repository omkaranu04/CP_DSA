#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d%d", &a, &b);
    int total = a * b;
    printf("%d", total - a);
    return 0;
}
