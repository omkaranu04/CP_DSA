#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->left = NULL;
    node->data = data;
    node->right = NULL;
    return node;
}
struct node *search(struct node *root, int query)
{
    if (root == NULL || root->data == query)
        return root;
    if (query < root->data)
        search(root->left, query);
    else
        search(root->right, query);
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        printf("Key is already present");
    return node;
}
void printTree(struct node *node, int level)
{
    if (node == NULL)
        return;
    printTree(node->left, level + 1);
    printf("%d [%d]  ", node->data, level);
    printTree(node->right, level + 1);
}
void printPostorder(struct node *node, int level)
{
    if (node == NULL)
        return;
    printPostorder(node->left, level + 1);
    printPostorder(node->right, level + 1);
    printf("%d [%d]  ", node->data, level);
}
void printPreorder(struct node *node)
{
    if (node == NULL)
        return;
    printf("%d", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}
void printInorder(struct node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d", node->data);
    printInorder(node->right);
}
int getMax(struct node *node)
{
    while (node->right != NULL)
        node = node->right;
    return node->data;
}
int getMin(struct node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node->data;
}
struct node *getmin(struct node *node)
{
    if (node->left != NULL)
        return getmin(node->left);
    else
        return node;
}
struct node *getmax(struct node *node)
{
    if (node->right != NULL)
        return getmin(node->right);
    else
        return node;
}
struct node *delete(struct node *node, int key)
{
    if (node == NULL)
        return NULL;
    if (key < node->data) // left-side
        node->left = delete (node->left, key);
    else if (key > node->data) // right side
        node->right = delete (node->right, key);
    else // key is same as root
    {
        if (node->left == NULL && node->right == NULL) // it is a leaf node
        {
            free(node);
            return NULL;
        }
        else if (node->left != NULL && node->right == NULL) // it has a left child
        {
            struct node *temp = node->left;
            free(node);
            return temp;
        }
        else if (node->left == NULL && node->right != NULL) // it has a right child
        {
            struct node *temp = node->right;
            free(node);
            return temp;
        }
        if (node->left != NULL && node->right != NULL) // it has 2 children
        {
            struct node *temp = getmin(node->right);
            node->data = temp->data;
            node->right = delete (node->right, temp->data);
        }
    }
    return node;
}
int main(int argc, char const *argv[])
{
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct node *root = NULL;
    for (int i = 0; i < 9; i++)
    {
        root = insert(root, a[i]);
        printPostorder(root, 0);
        printf("\n");
    }
}