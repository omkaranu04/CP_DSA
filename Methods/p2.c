#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a < b ? b : a;
}

int countCatches(int arr[], int n, int d)
{
    int catches = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {                                  // Check if the current person is innocent
            int left = max(0, i - d);      // Calculate the leftmost index that can be caught
            int right = min(n - 1, i + d); // Calculate the rightmost index that can be caught

            // Search for a dracula in the range [left, right] and catch them if found
            int j;
            for (j = left; j <= right; j++)
            {
                if (arr[j] == 1)
                {
                    catches++;
                    arr[j] = 2; // Mark the caught dracula as 2 to avoid counting it again
                    break;
                }
            }
        }
    }

    return catches;
}

int main() {
    int n, d;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array (0 for innocent person, 1 for dracula):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the distance d: ");
    scanf("%d", &d);

    int totalCatches = countCatches(arr, n, d);
    printf("Total number of catches: %d\n", totalCatches);

    return 0;
}
