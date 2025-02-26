#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function with two-pointer approach
int modified_partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choose the first element as the pivot
    int left = low;
    int right = high;

    while (1)
    {
        while (arr[left] <= pivot && left < high)
            left++;
        while (arr[right] > pivot)
            right--;

        if (left >= right)
            break;
        else
            swap(&arr[left], &arr[right]);
    }

    // Swap the pivot with the element at the right index
    swap(&arr[low], &arr[right]);

    return right;
}

// Quicksort function
void modified_quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = modified_partition(arr, low, high);
        modified_quicksort(arr, low, pivot_index);
        modified_quicksort(arr, pivot_index + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 2, 9, 6, 23, 12, 34, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    modified_quicksort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
