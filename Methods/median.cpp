#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
int median(int a[], int p, int r, int i)
{
    if (p == r)
        return a[r];
    int q = partition(a, p, r);
    if (q == i)
        return a[q];
    if (i < q)
        return median(a, p, q - 1, i);
    else
        return median(a, q + 1, r, i);
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
    cout << median(a, 0, n - 1, 2) << endl;
    return 0;
}