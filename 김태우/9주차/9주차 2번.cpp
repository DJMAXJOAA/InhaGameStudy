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
class Solution
{
    int ans = INT_MIN;
public:
    int DFS(TreeNode* root)
    {
        // make two DFS in binary tree
        // should find specific points of problem
        if (root == NULL) return 0;
        int left = max(DFS(root->left), 0);
        int right = max(DFS(root->right), 0);
        int temp = root->val + left + right;

        // save sum of final root of tree
        ans = max(ans, temp);

        //should be not branched to make path
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root)
    {
        DFS(root);
        return ans;
    }
};