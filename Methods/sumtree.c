#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
bool leaf(struct node *node)
{
    if (node == NULL)
        return false;
    if (node->right == NULL && node->left == NULL)
        return true;
    return false;
}
bool sum_tree(struct node *node)
{
    if (node == NULL || leaf(node))
    {
        return true;
    }
    int leftSum, rightSum;
    if (sum_tree(node->left) && sum_tree(node->right))
    {
        if (node->left == NULL)
            leftSum = 0;
        else if (leaf(node->left))
            leftSum = node->left->data;
        else
            leftSum = 2 * (node->left->data);

        if (node->right == NULL)
            rightSum = 0;
        else if (leaf(node->right))
            rightSum = node->right->data;
        else
            rightSum = 2 * (node->right->data);

        return (node->data == leftSum + rightSum);
    }
}
int main(int argc, char const *argv[])
{
    
}