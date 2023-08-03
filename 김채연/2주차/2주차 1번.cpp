// Q1. [leet code] Maximum Depth of Binary Tree
// 
// 이진 트리의 최대 깊이 구하기
// 노드를 순회하면서 각 노드에서의 최대 깊이를 계산한다.

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
        return max(left_cnt, right_cnt); // 둘 중 더 깊은거 반환.
    }
};