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

// DFS FUCNTION
void dfs(struct graph *g, int vertex)
{
    g->visit[vertex] = 1;
    int child_v;
    struct node *travel = g->adjacencyList[vertex];
    while (travel != NULL)
    {
        child_v = travel->data;
        if (g->visit[child_v] != 1)
        {
            dfs(g, child_v);
        }
        travel = travel->next;
    }
}

int main(int argc, char const *argv[])
{
    
}
