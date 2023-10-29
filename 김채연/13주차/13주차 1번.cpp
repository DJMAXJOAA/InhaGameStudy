class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // 루트가 같은 애들의 자식들까지 같은지 확인.
        if (!p && !q) return true; //l,r의 자식들까지 다 같은지 확인 후 둘다 똑같이 끝나면 true
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); //root의 자식들 계속 비교 (둘다 자식들 null일때 까지)
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) { //같은 root를 찾고
        if (!root || !subRoot)
            return false;

        if (isSameTree(root, subRoot))//자식들 똑같은지 확인하러
            return true; 

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);//같은 root 다시 찾기..

    }
};