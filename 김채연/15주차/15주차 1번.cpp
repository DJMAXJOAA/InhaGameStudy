// 이진트리 찾기.

class Solution {
public:
    bool isValidBST(TreeNode* root) {

        if (root->left == NULL && root->right == NULL)
            return true;

        if (root->left->val >= root->val)
            return false;

        if (root->right->val <= root->val)
            return false;

        if (isValidBST(root->left))
            return isValidBST(root->right);
    }
};

class Solution {

public:
    TreeNode* previous = nullptr;
    //recursive
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!isValidBST(root->left)) {
            return false;
        }

        if (previous && previous->val >= root->val) {
            return false;
        }

        previous = root;

        return isValidBST(root->right);

    }
}