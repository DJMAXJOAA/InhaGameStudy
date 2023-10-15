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
    map<int, vector<int>> M;

    void traverse(TreeNode* node, int depth) {
        if(node == nullptr)
            return;

        M[depth].push_back(node->val);
        traverse(node->left, depth+1);
        traverse(node->right, depth+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        traverse(root, 0);

        for(auto iter = M.begin(); iter != M.end(); iter++) {
            ans.push_back(iter->second);
        }

        return ans;
    }
};