
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *helper(vector<int> &inorder, vector<int> &preorder, map<int, int> &mp, int inl, int inr, int prel, int prer)
{
    if (inr < inl)
        return NULL;
    int idx = mp[preorder[prel]];
    Node *tmp = new Node(inorder[idx]);
    int leftsize = idx - inl;
    tmp->left = helper(inorder, preorder, mp, inl, idx - 1, prel + 1, prel + leftsize);
    tmp->right = helper(inorder, preorder, mp, idx + 1, inr, prel + leftsize + 1, prer);
    return tmp;
}

Node *getBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
        mp[inorder[i]] = i;

    int n = inorder.size();
    return helper(inorder, preorder, mp, 0, n - 1, 0, n - 1);
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
        vector<int> arr1(n);
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        vector<int> arr2(n);
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        Node *tree = getBinaryTree(arr1, arr2);
        vector<int> ans;
        generateArray(tree, ans);
        for (auto v : ans)
            cout << v << " ";
        cout << "\n";
    }
    return 0;
}
