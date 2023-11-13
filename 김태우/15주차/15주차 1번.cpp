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
    vector<int> tree;

public:
    void MakeOrder(TreeNode* node)
    {
        if (node == NULL) return;
        MakeOrder(node->left);
        tree.push_back(node->val);
        MakeOrder(node->right);
    }

    bool isValidBST(TreeNode* root)
    {
        if (root == NULL) return true;
        MakeOrder(root);
        for (int i = 1; i < tree.size(); i++)
        {
            if (tree[i - 1] >= tree[i])
                return false;
        }

        return true;
    }
};