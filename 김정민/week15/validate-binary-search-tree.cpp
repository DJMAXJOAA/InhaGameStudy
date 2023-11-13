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
    bool flag = true;
    vector<int> V;
 
    
    void traverse(TreeNode* node) {
        if(node == nullptr) {
            return;
        }

        traverse(node->left);

        if(!V.empty()) {
            if(V.back() >= node->val) {
                flag = false;
                return;
            }
        }
        V.push_back(node->val);

        traverse(node->right);
    }

    bool isValidBST(TreeNode* root) {
        traverse(root);
        return flag;
    }
};