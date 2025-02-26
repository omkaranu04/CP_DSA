#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}
struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->left = NULL;
    node->data = data;
    node->right = NULL;
    node->height = 0;
    return node;
}
int height(struct node *node) // helper function to get height of the node
{
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}
struct node *rightRotate(struct node *prt) // helper function to perform single right rotation
{
    struct node *chd = prt->left;
    prt->left = chd->right;
    prt->height = height(prt);
    chd->right = prt;
    chd->height = height(chd);
    prt = chd;
    return prt;
}
struct node *leftRotate(struct node *prt) // helper function to perform single ledt rotation
{
    struct node *chd = prt->right;
    prt->right = chd->left;
    prt->height = height(prt);
    chd->left = prt;
    chd->height = height(chd);
    prt = chd;
    return prt;
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
struct node *retrace(struct node *node) // the retrace function to get the AVL get balanced
{
    if (node == NULL)
        return node;
    if (height(node->left) - height(node->right) > 1) // left-heavy
    {
        // if left sub-tree is right heavy
        if (height(node->left->left) < height(node->left->right))
            node->left = leftRotate(node->left);
        node = rightRotate(node);
    }
    if (height(node->right) - height(node->left) > 1) // right-heavy
    {
        // if right sub-tree is left heavy
        if (height(node->right->left) > height(node->right->right))
            node->right = rightRotate(node->right);
        node = leftRotate(node);
    }
    node->height = height(node);
    return node;
}
struct node *insert(struct node *node, int key) // to insert a new node in AVL
{
    if (node == NULL)
        return retrace(newNode(key));
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        printf("The key is already present!");
    node = retrace(node);
    return node;
}
struct node *delete(struct node *node, int key) // to delete a node in the AVL
{
    if (node == NULL)
        return NULL;
    else if (key < node->data)
        delete (node->left, key);
    else if (key > node->data)
        delete (node->right, key);
    else
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
    node = retrace(node);
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
int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++)
    {
        root = insert(root, a[i]);
        printTree(root, 0);
        printf("\n");
    }

    return 0;
}