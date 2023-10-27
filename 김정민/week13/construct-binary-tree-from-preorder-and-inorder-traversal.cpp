
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
    unordered_map<int, int> inorderMap;
    unordered_map<int, int> preorderMap;

    // st, en = inorder idx
    int findRoot(int st, int en, vector<int>& inorder) {
        int idx = 99999;

        for(int i=st; i<=en; i++) {
            int cur = inorder[i];
            idx = min(idx, preorderMap[cur]);
        }

        return idx;
    }

    // st, en = inorder idx
    // preIdx = root idx
    TreeNode* make(int st, int en, int preIdx, vector<int>& preorder, vector<int>& inorder) {
        if(st > en) return nullptr;

        int val = preorder[preIdx];
        TreeNode* node = new TreeNode(val);
        int inIdx = inorderMap[val];

        node->left = make(st, inIdx-1, findRoot(st, inIdx-1, inorder), preorder, inorder);
        node->right = make(inIdx+1, en, findRoot(inIdx+1, en, inorder), preorder, inorder);
        
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
            preorderMap[preorder[i]] = i;
        }

        return make(0, preorder.size()-1, findRoot(0, preorder.size()-1, inorder), preorder, inorder);
    }
};