#include <stdio.h>
#include <stdlib.h>
void merge(int a[], int b[], int c[], int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }
    if (i == m)
    {
        for (int p = j; p < n; p++)
        {
            c[k] = b[p];
            k++;
        }
    }
    else
    {
        for (int p = i; p < m; p++)
        {
            c[k] = a[p];
            k++;
        }
    }
}
void mergeSort(int a[], int n)
{
    int i, j, k, m;
    if (n > 1)
    {
        k = n / 2;
        m = n - k;
        int b[k], c[m];
        for (i = 0; i < k; i++)
        {
            b[i] = a[i];
        }
        for (j = k; j < n; j++)
        {
            c[j - k] = a[j];
        }
        mergeSort(b, k);
        mergeSort(c, m);
        merge(b, c, a, k, m);
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    mergeSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}