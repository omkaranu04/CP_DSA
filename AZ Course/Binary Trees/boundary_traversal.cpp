#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool isLeaf(Node *root)
{
    return root && !root->left && !root->right;
}
void addLeft(Node *root, vector<int> &a)
{
    if (!root || isLeaf(root))
        return;
    a.push_back(root->val);
    if (root->left)
        addLeft(root->left, a);
    else
        addLeft(root->right, a);
}
void addLeaf(Node *root, vector<int> &a)
{
    if (!root)
        return;
    if (isLeaf(root))
    {
        a.push_back(root->val);
        return;
    }
    addLeaf(root->left, a);
    addLeaf(root->right, a);
}
void addRight(Node *root, vector<int> &a)
{
    if (!root || isLeaf(root))
        return;
    if (root->right)
        addRight(root->right, a);
    else
        addRight(root->left, a);
    a.push_back(root->val);
}
void printBoundary(struct Node *root)
{
    vector<int> ans;
    if (!root)
        return;
    if (!isLeaf(root))
        ans.push_back(root->val);
    if (root->left)
        addLeft(root->left, ans);
    addLeaf(root, ans);
    if (root->right)
        addRight(root->right, ans);

    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

Node *getBinaryTree(vector<int> &num, int *ind)
{
    if (num[*ind] == -1)
        return NULL;
    Node *node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num, ind);
    (*ind)++;
    node->right = getBinaryTree(num, ind);
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        assert(n <= 1000000);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ind = 0;
        Node *tree = getBinaryTree(arr, &ind);
        printBoundary(tree);
    }
    return 0;
}
