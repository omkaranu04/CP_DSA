
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

bool isIsomorphic(Node *t1, Node *t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    if (t1->val != t2->val)
        return false;
    bool b1 = isIsomorphic(t1->left, t2->left) && isIsomorphic(t1->right, t2->right);
    bool b2 = isIsomorphic(t1->left, t2->right) && isIsomorphic(t1->right, t2->left);
    return b1 || b2;
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

void generateArray(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        ans.push_back(-1);
        return;
    }
    ans.push_back(root->val);
    generateArray(root->left, ans);
    generateArray(root->right, ans);
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
        Node *tree1 = getBinaryTree(arr, &ind);
        arr.clear();
        cin >> n;
        assert(n <= 1000000);
        arr.resize(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        ind = 0;
        Node *tree2 = getBinaryTree(arr, &ind);
        if (isIsomorphic(tree1, tree2))
        {
            cout << "yes\n";
        }
        else
            cout << "no\n";
    }
    return 0;
}