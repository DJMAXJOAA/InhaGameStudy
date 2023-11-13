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
    int cnt = 0;
    int num = 0;
    int ans = 0;

    void traverse(TreeNode* node) {
        if(node == nullptr)
            return;
        
        traverse(node->left);

        num++;
        if(num == cnt)
            ans = node->val;

        traverse(node->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        cnt = k;
        traverse(root);
        return ans;
    }
};