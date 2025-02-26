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
    int *recurr_stack;
    int *inDegree;
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
    graph->recurr_stack = (int *)malloc((vertices + 1) * sizeof(int));
    graph->inDegree = (int *)malloc((vertices + 1) * sizeof(int));

    for (int i = 1; i <= vertices; i++)
    {
        graph->adjacencyList[i] = NULL;
        graph->visit[i] = 0;
        graph->recurr_stack[i] = 0;
        graph->inDegree[i] = 0;
    }

    return graph;
}
void addEdge(struct graph *g, int source, int desti)
{
    struct node *node = createNode(desti);
    node->next = g->adjacencyList[source];
    g->adjacencyList[source] = node;
    g->inDegree[desti]++;
}
// GRAPH IMPLEMENTATION ENDS

// FUNCTION TO DETECT IF A CYCLE IS FORMED IN THE GRAPH
int cycle(struct graph *g, int v)
{
    g->visit[v] = 1;
    g->recurr_stack[v] = 1;
    int answer = 0;

    int child_v;
    struct node *travel = g->adjacencyList[v];
    while (travel != NULL)
    {
        child_v = travel->data;
        if (g->recurr_stack[child_v] == 1)
        {
            answer = 1;
            break;
        }
        if (g->visit[child_v] == 0)
        {
            answer |= cycle(g, child_v);
        }
        travel = travel->next;
    }
    g->recurr_stack[v] = 0;
    return answer;
}
int ifCycleIsPresent(struct graph *g, int n)
{
    int i, answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g->visit[i] == 0)
        {
            answer |= cycle(g, i);
        }
    }
    return answer;
}

// FUNCTION FOR TOPOLOGICAL SORT
void topoSort(struct graph *g, int n, int *topo)
{
    if (ifCycleIsPresent(g, n))
    {
        printf("\nNot a Directed Acyclic Graph\n");
        return;
    }
    struct queue q = init();
    int i, idx = 0;
    for (i = 1; i <= n; i++)
    {
        if (g->inDegree[i] == 0)
            q = enqueue(q, i);
    }

    int curr_v, next_v;
    while (!isEmpty(q))
    {
        curr_v = front(q);
        q = dequeue(q);

        topo[idx] = curr_v;
        idx++;

        struct node *travel = g->adjacencyList[curr_v];
        while (travel != NULL)
        {
            next_v = travel->data;
            g->inDegree[next_v]--;
            if (g->inDegree[next_v] == 0)
            {
                q = enqueue(q, next_v);
            }
            travel = travel->next;
        }
    }
}

// TOPOLOGICAL SORT USING DFS
void dfs(struct graph *g, int v, int *topo, int *idx)
{
    g->visit[v] = 1;
    int child_v;
    struct node *travel = g->adjacencyList[v];

    while (travel != NULL)
    {
        child_v = travel->data;
        if (g->visit[child_v] != 1)
        {
            dfs(g, child_v, topo, idx);
        }
        travel = travel->next;
    }
    topo[*idx] = v;
    *idx = *idx + 1;
}
void reverse(int *a, int size)
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}
void topoSortDfs(struct graph *g, int n, int *topo)
{
    if (ifCycleIsPresent(g, n))
    {
        printf("\nNot a Directed Acyclic Graph\n");
        return;
    }

    int idx = 0;
    for (int i = 1; i <= n; i++)
    {
        g->visit[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (g->visit[i] == 0)
            dfs(g, i, topo, &idx);
    }
    reverse(topo, idx);
}
int main()
{
    int n, m, i;
    int x, y;

    scanf("%d %d", &n, &m);

    struct graph *newGraph = createGraph(n);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        addEdge(newGraph, x, y);
    }

    int *sequence = (int *)malloc((n + 1) * sizeof(int));

    topoSort(newGraph, n, sequence);
    // topoSortDfs(newGraph, n, sequence);

    for (i = 0; i < n; i++)
    {
        printf("%d ", sequence[i]);
    }
}