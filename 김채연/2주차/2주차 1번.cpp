// Q1. [leet code] Maximum Depth of Binary Tree
// 
// ���� Ʈ���� �ִ� ���� ���ϱ�
// ��带 ��ȸ�ϸ鼭 �� ��忡���� �ִ� ���̸� ����Ѵ�.

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_cnt = maxDepth(root->left);
        int right_cnt = maxDepth(root->right);;
        left_cnt += 1;
        right_cnt += 1;
        return max(left_cnt, right_cnt); // �� �� �� ������ ��ȯ.
    }
};