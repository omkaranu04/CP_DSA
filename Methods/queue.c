#include <stdio.h>
#include <stdlib.h>
struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
        printf("Queue is Full\n");
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
        printf("Queue is Empty\n");
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}
int main(int argc, char const *argv[])
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    int arr[6] = {34, 567, 23, 234, 676, 1};
    for (int i = 0; i < 6; i++)
    {
        enqueue(&q, arr[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d  ", q.arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Dequeue : %d\n", dequeue(&q));
    }

    return 0;
}
