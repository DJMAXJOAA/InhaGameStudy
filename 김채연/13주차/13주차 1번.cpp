class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // ��Ʈ�� ���� �ֵ��� �ڽĵ���� ������ Ȯ��.
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //���� root�� ã��
        if (!root || !subRoot)
            return false;

        if (isSameTree(root, subRoot))
            return true; 

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }
};