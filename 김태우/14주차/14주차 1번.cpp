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
public:
    TreeNode* MakeTree(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int start, int end)
    {
        if (start >= end)
        {
            return nullptr;
        }

        TreeNode* temp = new TreeNode(preorder[preorderIndex]);
        int inorderIndex = start;

        while (inorder[inorderIndex] != temp->val)
        {
            inorderIndex++;
        }

        preorderIndex++;

        temp->left = MakeTree(preorder, inorder, preorderIndex, start, inorderIndex);
        temp->right = MakeTree(preorder, inorder, preorderIndex, inorderIndex + 1, end);

        return temp;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // should memorize index because when it passed never go back
        int preorderIndex = 0;
        return MakeTree(preorder, inorder, preorderIndex, 0, inorder.size());
    }
};