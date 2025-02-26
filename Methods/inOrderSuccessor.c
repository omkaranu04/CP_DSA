class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        if(root==NULL||x==NULL) return NULL;
        Node *suc = NULL;
        while(root!=NULL)
        {
            if(root->data<=x->data) root = root->right;
            else
            {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
};