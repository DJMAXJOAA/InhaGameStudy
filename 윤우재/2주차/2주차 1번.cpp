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
    int depth = 1;
    int DepthMax = 1;

    int maxDepth(TreeNode* root) {
        
        if(root==nullptr)
            return 0;
        if(root->left != nullptr)
        {
            depth++;
            maxDepth(root->left);
        }
        if(root->right != nullptr)
        {
            depth++;
            maxDepth(root->right);
        }

        if(depth>DepthMax) DepthMax = depth;
        depth--;
        
        return DepthMax;
    }
};