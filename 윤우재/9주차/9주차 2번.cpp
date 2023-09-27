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
private: 
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        //좌->부모->우로 이동해서 구해지는 경로의 노드들의 합 중 가장 큰 값 구하기
        //dfs로 싹다 탐색하면서 path sum들을 갱신할 수 없나?
       maxSum = INT_MIN;
       dfs(root);
       return maxSum;
    }

    int dfs(TreeNode* root)
    {
        if(nullptr == root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, left + right + root->val);
        return root->val + max(left, right);
    }
};