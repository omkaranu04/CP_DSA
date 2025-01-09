#include <stdio.h>
void insertionSort(int a[], int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        int key = a[i];
        int j = i + 1;
        while (j < n && a[j] < key)
        {
            a[j - 1] = a[j];
            j = j + 1;
        }
        a[j - 1] = key;
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
    insertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}