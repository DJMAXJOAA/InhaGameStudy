class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // 루트가 같은 애들의 자식들까지 같은지 확인.
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //같은 root를 찾고
        if (!root || !subRoot)
            return false;

        if (isSameTree(root, subRoot))
            return true; 

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};