#include <stdio.h>
#define maxlen 10000
typedef struct
{
    float v;
    float w;
    float vpw;
} filling;
void mergeY(filling arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    filling left[maxlen], right[maxlen];
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[m + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (k <= r)
    {
        if (left[i].vpw > right[j].vpw)
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
}
void mergeSort(filling arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    mergeY(arr, l, mid, r);
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    filling maal[maxlen];
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &maal[i].v, &maal[i].w);
        maal[i].vpw = maal[i].v / maal[i].w;
    }
    mergeSort(maal, 0, n - 1);
    float load = 0, capacity;
    printf("Enter capacity : ");
    scanf("%f", &capacity);
    float value = 0;
    for (int i = 0; i < n && load < capacity; i++)
    {
        if (maal[i].w <= capacity - load)
        {
            load += maal[i].w;
            value += maal[i].v;
            printf("%f ", value);
        }
        else
        {
            float fraction = (capacity - load) / maal[i].w;
            load += (capacity - load);
            value += fraction * maal[i].v;
            printf("%f ", value);
            break;
        }
    }
    printf("\n");
    printf("%f\n", value);
    return 0;
}