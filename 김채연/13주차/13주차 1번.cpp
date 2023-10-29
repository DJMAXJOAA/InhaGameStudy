class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // ��Ʈ�� ���� �ֵ��� �ڽĵ���� ������ Ȯ��.
        if (!p && !q) return true; //l,r�� �ڽĵ���� �� ������ Ȯ�� �� �Ѵ� �Ȱ��� ������ true
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); //root�� �ڽĵ� ��� �� (�Ѵ� �ڽĵ� null�϶� ����)
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //���� root�� ã��
        if (!root || !subRoot)
            return false;

        if (isSameTree(root, subRoot))//�ڽĵ� �Ȱ����� Ȯ���Ϸ�
            return true; 

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);//���� root �ٽ� ã��..

    }
};