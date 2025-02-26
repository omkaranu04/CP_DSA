#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int maxCross(int a[], int p, int q, int r)
{
    int lsum = -__INT_MAX__;
    int rsum = -__INT_MAX__;
    int sum = 0;
    for (int i = q; i >= p; i--)
    {
        sum += a[i];
        if (sum > lsum)
            lsum = sum;
    }
    sum = 0;
    for (int i = q + 1; i <= r; i++)
    {
        sum += a[i];
        if (sum > rsum)
            rsum = sum;
    }
    return (lsum + rsum);
}
int maxSubArray(int a[], int p, int r)
{
    if (p == r)
        return a[p];
    int q = (p + r) / 2;
    int L = maxSubArray(a, p, q);
    int R = maxSubArray(a, q + 1, r);
    int C = maxCross(a, p, q, r);
    return max(L, max(R, C));
}
int main(int argc, char const *argv[])
{
    int a[] = {-1, 3, 4, -5, 9, -2};
    int ans = maxSubArray(a, 0, 5);
    printf("%d\n", ans);
    return 0;
}
