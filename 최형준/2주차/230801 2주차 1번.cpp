/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_depth = 0;
public:
    void nodeDepth(TreeNode* node, int index)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            max_depth = max(max_depth, index);
            return;
        }
        if (node->left != nullptr)
        {
            nodeDepth(node->left, index + 1);
        }
        if (node->right != nullptr)
        {
            nodeDepth(node->right, index + 1);
        }
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        max_depth = 0;
        nodeDepth(root, 1);
        return max_depth;
    }
};