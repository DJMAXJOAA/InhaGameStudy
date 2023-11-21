class Solution {//p,q 사이값 찾기.
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }
        return NULL;
    }
};