class Solution {
public:
    TreeNode* build_tree(vector<int> pre, vector<int> in, int left, int right, int root_idx) {
        // left, right -> index of in
        // root_idx -> index of pre
        if (left > right) /* base case */
            return NULL;
        int pivot = left;
        /* search where is the index of root value in the inorder[] */
        for (pivot = left; pivot <= right; pivot++) // O(n)
            if (in[pivot] == pre[root_idx])
                break;

        TreeNode* node = new TreeNode;
        node->val = pre[root_idx];
        node->left = build_tree(pre, in, left, pivot - 1, root_idx + 1);
        node->right = build_tree(pre, in, pivot + 1, right, root_idx + (pivot - left + 1));
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build_tree(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};