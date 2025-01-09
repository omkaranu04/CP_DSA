#include <stdio.h>
#include <stdlib.h>
// QUEUE IMPLEMENTATION BEGINS
#define len 100
struct queue
{
    int arr[len];
    int front;
    int back;
};
struct queue init()
{
    struct queue q;
    q.front = 0;
    q.back = len - 1;
    return q;
}
int isEmpty(struct queue q)
{
    if (q.front == (q.back + 1) % len)
        return 1;
    return 0;
}
int front(struct queue q)
{
    return q.arr[q.front];
}
struct queue enqueue(struct queue q, int val)
{
    q.back = (++q.back) % len;
    q.arr[q.back] = val;
    return q;
}
struct queue dequeue(struct queue q)
{
    q.front = (++q.front) % len;
    return q;
}
// QUEUE IMPLEMENTATION ENDS

// GRAPH IMPLEMENTATION BEGINS
struct node
{
    int data;
    struct node *next;
};
struct graph
{
    int data;
    struct node **adjacencyList;
    int *visit;
};
struct node *createNode(int val)
{
    struct node *vertex = (struct node *)malloc(sizeof(struct node));
    vertex->data = val;
    vertex->next = NULL;
    return vertex;
}
struct graph *createGraph(int vertices)
{
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));

    graph->data = vertices;
    graph->adjacencyList = (struct node **)malloc((vertices + 1) * sizeof(struct node *));
    graph->visit = (int *)malloc((vertices + 1) * sizeof(int));

    for (int i = 1; i <= vertices; i++)
    {
        graph->adjacencyList[i] = NULL;
        graph->visit[i] = 0;
    }

    return graph;
}
void addEdge(struct graph *g, int source, int desti)
{
    struct node *node = createNode(desti);
    node->next = g->adjacencyList[source];
    g->adjacencyList[source] = node;
}
// GRAPH IMPLEMENTATION ENDS

// BFS FUNCTION
void bfs(struct graph *g, int source, int *distance)
{
    distance[source] = 0;
    g->visit[source] = 1;

    // QUEUE REQUIRED FOR BFS
    struct queue q = init();
    q = enqueue(q, source);

    int curr_v, child_v;
    while (!isEmpty(q))
    {
        curr_v = front(q);
        q = dequeue(q);

        struct node *travel = g->adjacencyList[curr_v];
        while (travel != NULL)
        {
            child_v = travel->data;
            if (g->visit[child_v] != 1)
            {
                g->visit[child_v] = 1;
                distance[child_v] = distance[curr_v] + 1;
                enqueue(q, child_v);
            }
            travel = travel->next;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 5;
    struct graph *graph = createGraph(n);
    int distance[n + 1];
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);
    addEdge(graph, 2, 5);

    bfs(graph, 1, distance);

    for (int i = 1; i <= n; i++)
    {
        printf("%d  ", distance[i]);
    }

    return 0;
}
