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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftDepth = 1;
        int rightDepth = 1;
        if (root->left != nullptr)
            leftDepth += maxDepth(root->left);
        if (root->right != nullptr)
            rightDepth += maxDepth(root->right);

        return max(leftDepth, rightDepth);
    }
};