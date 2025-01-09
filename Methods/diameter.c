public:
    // Function to check if there is a path in the tree with a given sum.
    bool hasPathSum(Node *node, int sum) {
        // If the node is NULL, check if the remaining sum is 0.
        if (node == NULL) {
            return (sum == 0);
        }

        bool ans = false;
        int subSum = sum - node->data;

        // If the remaining sum is 0 and the node has no children, return true.
        if (subSum == 0 and node->left == NULL and node->right == NULL) return true;

        // Recursively check if there is a path with the remaining sum in the left and right subtrees.
        if (node->left) ans = ans || hasPathSum(node->left, subSum);
        if (node->right) ans = ans || hasPathSum(node->right, subSum);
        return ans