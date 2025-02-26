#include <bits/stdc++.h>
using namespace std;
int minIndex(int a[], int k, int size)
{
    int pos = k;
    for (int i = k + 1; i < size; i++)
    {
        if (a[i] < a[pos])
            pos = i;
    }
    return pos;
}
void selectionSort(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int m = minIndex(a, i, size);
        int temp = a[i];
        a[i] = a[m];
        a[m] = temp;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}