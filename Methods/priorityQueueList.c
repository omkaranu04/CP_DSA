// THIS IMPLEMENTATION IS FOR MINIMUM VARIANT OF PRIORITY QUEUE (MIN POP OUT FIRST)
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int priority;
    struct node *next;
};
struct node *newNode(int p)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->priority = p;
    temp->next = NULL;
    return temp;
}
int isEmpty(struct node *head)
{
    if (head == NULL)
        return 1;
    else
        return 0;
}
int getMin(struct node *head)
{
    if (isEmpty(head))
    {
        printf("Empty Priority Queue\n");
        exit(0);
    }
    return head->priority;
}
struct node *pop(struct node *head)
{
    if (isEmpty(head))
    {
        printf("Empty Priority Queue\n");
        exit(0);
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct node *push(struct node *head, int newNum) // thoda doubted hai slides mein
{
    struct node *nNode = newNode(newNum);
    if (head->priority < newNum) // in slides it is >
    {
        nNode->next = head;
        return nNode;
    }
    else
    {
        struct node *start = head;
        struct node *startPrev = head;
        while (newNum < start->priority) // in slides it is <
        {
            if (start->next != NULL)
            {
                startPrev = start;
                start = start->next;
            }
            else
            {
                start->next = nNode;
                return head;
            }
        }
        nNode->next = startPrev->next;
        startPrev->next = nNode;
        return head;
    }
}
