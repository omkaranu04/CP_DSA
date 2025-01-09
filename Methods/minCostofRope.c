// THIS IMPLEMENTATTION IS FOR MIN-HEAP
#include <stdio.h>
#include <stdlib.h>
#define capacity 100
int size = 0; // to track size of heap
// int H[capacity + 1]; // heap implementation has 1 indexed array
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
// HELPER METHODS FOR INDICES
int root()
{
    return 1;
}
int parent(int n)
{
    return n / 2;
}
int leftChild(int n)
{
    return 2 * n;
}
int rightChild(int n)
{
    return 2 * n + 1;
}
// HELPER METHODS FOR NODE TESTING
int hasParent(int n)
{
    if (n != root())
        return 1;
    else
        return 0;
}
int isNode(int n)
{
    if (n <= size)
        return 1;
    else
        return 0;
}
int getMin(int H[]) // Function to get the node with highest priority
{
    if (size == 0)
    {
        printf("Empty Priority Queue\n");
        exit(0);
    }
    return H[root()];
}
void shiftUp(int H[], int n) // Function to shift up the node in order to maintain the heap property
{
    while (hasParent(n) && (H[parent(n)] > H[n]))
    {
        swap(&H[parent(n)], &H[n]);
        n = parent(n);
    }
    // This is also called as Bubble-Up, Heapify-Up
}
void push(int H[], int newNum) // Function to insert new item
{
    if (size == capacity)
    {
        printf("Priority Queue Full\n");
        exit(0);
    }
    H[size + 1] = newNum;
    size++;
    shiftUp(H, size);
}
void shiftDown(int H[], int n) // Function to shift down the node in order to maintain the heap property
{
    while (isNode(leftChild(n)))
    {
        int child = leftChild(n);
        if (isNode(rightChild(n)) && (H[rightChild(n)] < H[leftChild(n)]))
        {
            child = rightChild(n);
        }
        if (H[n] > H[child])
        {
            swap(&H[n], &H[child]);
        }
        else
            break;
        n = child;
    }
    // This function is also called Bubble-Down, Heapify-Down
}
void pop(int H[])
{
    if (size == 0)
    {
        printf("Empty Priority Queue\n");
        exit(0);
    }
    H[root()] = H[size];
    size--;
    shiftDown(H, root());
}
void buildHeap(int arr[], int H[], int n)
{
    for (int i = 0; i < n; i++)
    {
        H[i + 1] = arr[i];
    }
    size = n;
    for (int i = size / 2; i >= 1; i--)
    {
        shiftDown(H, i);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {4, 2, 7, 6, 9};
    int n = sizeof(arr) / sizeof(arr[1]);
    printf("Array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int H[capacity + 1];
    buildHeap(arr, H, n);
    int sum = 0;
    while (size > 1)
    {
        int min1 = getMin(H);
        pop(H);
        int min2 = getMin(H);
        pop(H);
        sum += (min1 + min2);
        push(H, min1 + min2);
    }
    printf("%d\n", sum);
    return 0;
}