#include <stdio.h>
#include <stdlib.h>
// WEIGHTED GRAPH IMPLEMENTATION STARTS
struct node
{
    int data;
    int weight;
    struct node *next;
};
struct graph
{
    int data;
    struct node **adjacencyList;
    int *visit;
};
struct node *createNode(int val, int weight)
{
    struct node *vertex = (struct node *)malloc(sizeof(struct node));
    vertex->data = val;
    vertex->weight = weight;
    vertex->next = NULL;
    return vertex;
}
struct graph *createGraph(int vertices)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->data = vertices;
    g->adjacencyList = (struct node **)malloc((vertices + 1) * sizeof(struct node *));
    g->visit = (int *)malloc((vertices + 1) * sizeof(int));

    for (int i = 1; i <= vertices; i++)
    {
        g->adjacencyList[i] = NULL;
        g->visit[i] = 0;
    }
    return g;
}
void addEdge(struct graph *g, int source, int desti, int weight)
{
    struct node *newNode = createNode(desti, weight);
    newNode->next = g->adjacencyList[source];
    g->adjacencyList[source] = newNode;
}
// WEIGHTED GRAPH IMPLEMENTATION ENDS

// MINIMUM HEAP IMPLEMENTATION USING STRUCT BEGINS
struct pair
{
    int vertex;
    int reachDis;
};
void swap(struct pair *x, struct pair *y)
{
    struct pair temp = *x;
    *x = *y;
    *y = temp;
}
int size = 0;
/* Helper Functions for Heap Implementation */
int root() { return 1; }
int parent(int n) { return n / 2; }
int leftChild(int n) { return 2 * n; }
int rightChild(int n) { return 2 * n + 1; }
int hasParent(int n) { return n != root(); }
int isNode(int n) { return n <= size; };
struct pair front(struct pair H[]) { return H[root()]; }
void shiftUp(struct pair H[], int idx)
{
    while (hasParent(idx) && (H[parent(idx)].reachDis > H[idx].reachDis))
    {
        swap(&H[parent(idx)], &H[idx]);
        idx = parent(idx);
    }
}
void shiftDown(struct pair H[], int idx)
{
    while (isNode(leftChild(idx)))
    {
        int child = leftChild(idx);

        if (isNode(rightChild(idx)) && (H[rightChild(idx)].reachDis < H[leftChild(idx)].reachDis))
        {
            child = rightChild(idx);
        }
        if (H[idx].reachDis > H[child].reachDis)
        {
            swap(&H[idx], &H[child]);
        }
        else
            break;
        idx = child;
    }
}
void push(struct pair H[], struct pair new)
{
    size++;
    H[size] = new;
    shiftUp(H, size);
}
void pop(struct pair H[])
{
    H[root()] = H[size];
    size--;
    shiftDown(H, root());
}
// MINIMUM HEAP IMPLEMENTATION USING STRUCT ENDS

// DIJKSTRA ALGORITHM
void dijkstra(struct graph *g, int source, int n, int *dist)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    struct pair *pairs = (struct pair *)malloc((n + 1) * sizeof(struct pair));
    size = 0;

    struct pair temp = {source, 0};
    dist[source] = 0;
    push(pairs, temp);

    int curr_v, curr_dist, child_v, weight;
    struct node *travel;

    while (size > 0)
    {
        temp = front(pairs);
        curr_v = temp.vertex, curr_dist = temp.reachDis;
        pop(pairs);

        if (g->visit[curr_v] == 1)
            continue;
        g->visit[curr_v] = 1;

        travel = g->adjacencyList[curr_v];
        while (travel != NULL)
        {
            child_v = travel->data;
            weight = travel->weight;

            if (curr_dist + weight < dist[child_v])
            {
                dist[child_v] = curr_dist + weight;
                temp = (struct pair){child_v, dist[child_v]};
                push(pairs, temp);
            }
            travel = travel->next;
        }
    }
}
int main()
{
    int n, m, i;
    int x, y, wt;

    scanf("%d %d", &n, &m);

    struct graph *newGraph = createGraph(n);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &x, &y, &wt);
        addEdge(newGraph, x, y, wt);
    }

    int *dist = (int *)malloc((n + 1) * sizeof(int));
    dijkstra(newGraph, 1, n, dist);

    for (i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
}