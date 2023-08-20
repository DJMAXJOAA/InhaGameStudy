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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool left = true; 
        bool right = true;

        if(p == NULL && q == NULL)  return true;
        else if(p == NULL || q == NULL) return false;
        
        if(p->val != q->val)  return false;
            
        if(p->left != NULL || q->left != NULL)
            left = isSameTree(p->left, q->left);
        if(left == false)   return false;


        if(p->right != NULL || q->right != NULL)
            right =  isSameTree(p->right, q->right);
        if(right == false)  return false;

        return (left == right) ? true : false; 
    }
};
