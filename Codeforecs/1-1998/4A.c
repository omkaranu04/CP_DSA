#include<stdio.h>
int main(int argc, char const *argv[])
{
    int weight;
    scanf("%d", &weight);

    if(weight%2==0 && weight!=2) printf("YES");
    else if(weight == 2) printf("NO");
    else printf("NO");
    return 0;
}
